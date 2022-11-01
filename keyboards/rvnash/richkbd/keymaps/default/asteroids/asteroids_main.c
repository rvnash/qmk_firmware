#include QMK_KEYBOARD_H
#include "renderer.h"
#include "player.h"
#include "asteroids.h"

#define ASTEROIDS 27
#define LIVES 3

struct asteroid asteroids[ASTEROIDS];   //The asteroids
struct player p;                        //The player
struct player lives[LIVES];             //Player lives left
uint32_t next_loop;
static uint32_t asteroid_timer;
#define MS_PER_FRAME (1000/15)
int loop_count = 0;
uint32_t loop_timer;
int score;
bool game_over=false;

void asteroids_init(void)
{
    int i = 0;
    int j = 0;
    int offset = 0;
    struct vector2d translation = {-SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2};

    //set up icons used to represent player lives
    for (i = 0; i < LIVES; i++) {
        init_player(&lives[i]);
        lives[i].lives = 1;
        //shrink lives
        for (j = 0; j < P_VERTS; j++) {
            divide_vector(&lives[i].obj_vert[j], 2);
        }
        //convert screen space vector into world space
        struct vector2d top_left = {3 + offset, 5};
        add_vector(&top_left, &translation);
        lives[i].location = top_left;
        update_player(&lives[i]);
        offset += 5;
    }
    //set up player and asteroids in world space
    init_player(&p);
    init_asteroids(asteroids, ASTEROIDS);
    score = 0;
    next_loop = MS_PER_FRAME;
    asteroid_timer = timer_read32();
    loop_timer = timer_read32();
}

bool key_left = false;
bool key_right = false;
bool key_up = false;
void asteroids_process_record_quantum(keyrecord_t *record)
{
    if (record->event.key.col == 8 && record->event.key.row == 1) {
        key_left = record->event.pressed;
    }
    if (record->event.key.col == 9 && record->event.key.row == 1) {
        key_right = record->event.pressed;
    }
    if (record->event.key.col == 10 && record->event.key.row == 1) {
        key_up = record->event.pressed;
    }
    if (record->event.key.col == 7 && record->event.key.row == 1 && record->event.pressed && p.lives && p.alive) {
        shoot_bullet(&p);
    }
}

void draw_score(void)
{
    char tmp[6];
    snprintf(tmp, sizeof(tmp), "%5d", score);
    oled_set_cursor(16, 0);
    oled_write(tmp, false);
}

void asteroids_loop(void)
{
    oled_clear();
    if (game_over) {
        char tmp[6];
        snprintf(tmp, sizeof(tmp), "%-5d", score);
        oled_set_cursor(6, 2);
        oled_write("GAME OVER", false);
        oled_set_cursor(6, 3);
        oled_write("SCORE:", false);
        oled_set_cursor(13, 3);
        oled_write(tmp, false);
        return;
    }
    if (timer_elapsed32(loop_timer) >= 1000) {
        uprintf("astr loop cnt %d\n", loop_count);
        loop_timer = timer_read32();
        loop_count = 0;
    }
    loop_count++;
    if (key_up) {
        struct vector2d thrust = get_direction(&p);
        multiply_vector(&thrust, .09);
        apply_force(&p.velocity, thrust);
    }

    if (key_left) {
        rotate_player(&p, -11);
    }

    if (key_right) {
        rotate_player(&p, 11);
    }
    // draw to the pixel buffer
    draw_score();
    draw_player( &p);
    draw_player( &lives[0]);
    draw_player( &lives[1]);
    draw_player( &lives[2]);
    draw_asteroids(asteroids, ASTEROIDS);
    update_player(&p);
    bounds_player(&p);
    bounds_asteroids(asteroids, ASTEROIDS);


    if (p.alive && p.exploding_time == 0) {
        int res = collision_asteroids(asteroids, ASTEROIDS, &p.location, p.hit_radius);
        if (res != -1) { // Collision w/ astroid
            p.lives--;
            p.alive = false;
            p.exploding_time = timer_read();
            lives[p.lives].alive = false; // turn off icon
        }
    } else {
        int res = collision_asteroids(asteroids, ASTEROIDS, &p.location, 2*p.hit_radius);
        if ((res == -1 || !p.lives) && timer_elapsed(p.exploding_time) > 3000) {
            p.location.x = 0;
            p.location.y = 0;
            p.velocity.x = 0;
            p.velocity.y = 0;
            if (p.lives) {
                p.alive = true;
            } else {
                game_over = true;
            }
            p.exploding_time = 0;
        }
    }

    int i = 0;
    struct vector2d translation = {-SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2};
    for (i = 0; i < BULLETS; i++) {
        //only check for collision for bullets that are shown on screen
        if (p.bullets[i].alive) {
            //convert bullet screen space location to world space to compare
            //with asteroids world space to detect a collision
            struct vector2d world = add_vector_new(&p.bullets[i].location, &translation);
            int index = collision_asteroids(asteroids, ASTEROIDS, &world, 1);
            //collision occured
            if (index != -1) {
                switch (asteroids[index].size) {
                    case SMALL:
                        score += 5;
                    break;
                    case MEDIUM:
                        score += 2;
                    break;
                    case LARGE:
                        score += 1;
                    break;
                }
                asteroids[index].alive = 0;
                p.bullets[i].alive = false;
                if (asteroids[index].size != SMALL) {
                    spawn_asteroids(asteroids, ASTEROIDS, asteroids[index].size, asteroids[index].location);
                }
            }
        }
    }

    update_asteroids(asteroids, ASTEROIDS);

}

void asteroids_pump(void)
{
    if (timer_elapsed32(asteroid_timer) > next_loop) {
        next_loop += MS_PER_FRAME;
        asteroids_loop();
    }
}

