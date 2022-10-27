#include QMK_KEYBOARD_H
#include "renderer.h"
#include "player.h"
#include "asteroids.h"

#define ASTEROIDS 27
#define LIVES 3

struct asteroid asteroids[ASTEROIDS];		//The asteroids
struct player p;				//The player
struct player lives[LIVES];			//Player lives left
uint32_t next_loop;
static uint32_t asteroid_timer;
#define MS_PER_FRAME (1000/60)

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
		struct vector2d top_left = {20 + offset, 20};
		add_vector(&top_left, &translation);
		lives[i].location = top_left;
		update_player(&lives[i]);
		offset += 20;
	}
	//set up player and asteroids in world space
	init_player(&p);
	init_asteroids(asteroids, ASTEROIDS);
    next_loop = MS_PER_FRAME;
    asteroid_timer = timer_read32();
}

void asteroids_loop(void)
{
    if (false /* UP */) {

        struct vector2d thrust = get_direction(&p);
        multiply_vector(&thrust, .06);
        apply_force(&p.velocity, thrust);
    }

    if (false /* LEFT */) {

        rotate_player(&p, -4);
    }

    if (false /* RIGHT */) {

        rotate_player(&p, 4);
    }

    if (false /* fire */) {
        if (p.lives > 0) {
            shoot_bullet(&p);
        }
    }

    // draw to the pixel buffer
    oled_clear();
    draw_player( &p);
    draw_player( &lives[0]);
    draw_player( &lives[1]);
    draw_player( &lives[2]);
    draw_asteroids(asteroids, ASTEROIDS);
    update_player(&p);
    bounds_player(&p);
    bounds_asteroids(asteroids, ASTEROIDS);

    int res = collision_asteroids(asteroids, ASTEROIDS, &p.location, p.hit_radius);

    if (res != -1) {

        p.lives--;
        p.location.x = 0;
        p.location.y = 0;
        p.velocity.x = 0;
        p.velocity.y = 0;

        int i = LIVES - 1;

        for ( i = LIVES; i >= 0; i--) {

            if(lives[i].lives > 0) {

                lives[i].lives = 0;
                break;
            }
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
        oled_render();
    }
}

