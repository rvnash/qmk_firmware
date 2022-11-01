
//player.c
#include QMK_KEYBOARD_H
#include "renderer.h"
#include "player.h"

void init_player_location(struct player* p)
{
    p->location.x = 0;
    p->location.y = 0;
    p->velocity.x = 0;
    p->velocity.y = 0;
}

void init_player_verts(struct player* p)
{
    p->obj_vert[0].x = 0;
    p->obj_vert[0].y = 1.5;
    p->obj_vert[1].x = -1;
    p->obj_vert[1].y = -1;
    p->obj_vert[2].x = 1;
    p->obj_vert[2].y = -1;
    p->obj_vert[3].x = 0.75;
    p->obj_vert[3].y = -1;
    p->obj_vert[4].x = 0;
    p->obj_vert[4].y = -2.0;
    p->obj_vert[5].x = -0.75;
    p->obj_vert[5].y = -1;
    struct vector2d translation = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    for(int i = 0; i < P_VERTS; i++) {
        multiply_vector(&p->obj_vert[i], -1);
        multiply_vector(&p->obj_vert[i], 5);
        add_vector(&p->world_vert[i], &p->obj_vert[i]);
        add_vector(&p->world_vert[i], &translation);
    }
}

void init_player(struct player* p)
{
    p->hit_radius = 8;
    p->lives = 3;
    p->alive = true;
    p->exploding_time = 0;
    for(int i = 0; i < BULLETS; i++) {
        p->bullets[i].alive = false;
    }
    init_player_location(p);
    init_player_verts(p);
}

void apply_force(struct vector2d* velocity, struct vector2d v) {

    add_vector(velocity, &v);
}

struct vector2d get_direction(struct player* p) {

    struct vector2d direction = p->obj_vert[0];
    normalise_vector(&direction);

    return direction;
}

void shoot_bullet(struct player* p)
{
    int i = 0;
    for (i = 0; i < BULLETS; i++) {
        if (p->bullets[i].alive == false) {
            p->bullets[i].alive = true;
            p->bullets[i].location = p->world_vert[0];
            p->bullets[i].velocity = get_direction(p);
            multiply_vector(&p->bullets[i].velocity, 4.1);
            break;
        }
    }
}

void draw_player_line(struct player* p, int x1, int y1,int x2, int y2, int n)
{
    if (p->exploding_time) {
        int elapsed = timer_elapsed(p->exploding_time)/75;
        switch (n) {
            case 0:
                x1 += elapsed;
                y1 += elapsed;
                x2 += elapsed;
                y2 += elapsed;
                break;
            case 1:
                x1 -= elapsed;
                y1 -= elapsed;
                x2 -= elapsed;
                y2 -= elapsed;
                break;
            case 2:
                x1 -= elapsed;
                y1 += elapsed;
                x2 -= elapsed;
                y2 += elapsed;
                break;
            case 3:
                x1 += elapsed;
                y1 -= elapsed;
                x2 += elapsed;
                y2 -= elapsed;
                break;
            case 4:
                x1 -= elapsed/2;
                y1 += elapsed/2;
                x2 -= elapsed/2;
                y2 += elapsed/2;
                break;
        }
    }
    draw_line(x1, y1, x2, y2, 1);
}

bool flicker_last = false;
void draw_player(struct player* p, bool thrust)
{
    int i = 0;
    if (p->exploding_time != 0 || (p->alive && p->lives > 0)) {
        draw_player_line(p, p->world_vert[0].x, p->world_vert[0].y, p->world_vert[1].x, p->world_vert[1].y, 0);
        draw_player_line(p, p->world_vert[1].x, p->world_vert[1].y, p->world_vert[2].x, p->world_vert[2].y, 1);
        draw_player_line(p, p->world_vert[2].x, p->world_vert[2].y, p->world_vert[0].x, p->world_vert[0].y, 2);
        if (thrust && !p->exploding_time) {
            if (flicker_last) {
                draw_player_line(p, p->world_vert[3].x, p->world_vert[3].y, p->world_vert[4].x, p->world_vert[4].y, 3);
                draw_player_line(p, p->world_vert[4].x, p->world_vert[4].y, p->world_vert[5].x, p->world_vert[5].y, 4);
            }
            flicker_last = !flicker_last;
        }
    }
    //draw verts representing the bullets
    for (i = 0; i < BULLETS; i++) {
        if (p->bullets[i].alive) {
            draw_pixel(p->bullets[i].location.x, p->bullets[i].location.y, 1);
        }
    }
}

void update_player(struct player* p)
{
    limit_vector(&p->velocity, 2);
    add_vector(&p->location, &p->velocity);
    struct vector2d translation = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    int i = 0;
    for (i =0; i < P_VERTS; i++) {
        p->world_vert[i] = add_vector_new(&p->obj_vert[i], &p->location);
        add_vector(&p->world_vert[i], &translation);
    }
    for (i = 0; i < BULLETS; i++) {
        add_vector(&p->bullets[i].location, &p->bullets[i].velocity);
    }
}

void rotate_player(struct player* p, float degrees)
{
    int i = 0;
    for (i =0; i < P_VERTS; i++) {
        rotate_vector(&p->obj_vert[i], degrees);
    }
}

void bounds_player(struct player* p)
{
    if (p->location.x < -SCREEN_WIDTH / 2) {
        p->location.x = SCREEN_WIDTH / 2;
    }
    if (p->location.x > SCREEN_WIDTH / 2) {
        p->location.x = -SCREEN_WIDTH / 2;
    }
    if (p->location.y < -SCREEN_HEIGHT / 2) {
        p->location.y = SCREEN_HEIGHT / 2;
    }
    if (p->location.y > SCREEN_HEIGHT / 2) {
        p->location.y = -SCREEN_HEIGHT / 2;
    }
    //bullet is out of bounds, reset bullet to be shot again
    //bullets are in world space
    for (int i = 0; i < BULLETS; i++) {
        if (p->bullets[i].location.x < 0 || p->bullets[i].location.x >= SCREEN_WIDTH) {
            p->bullets[i].alive = false;
        }
        if (p->bullets[i].location.y < 0 || p->bullets[i].location.y >= SCREEN_HEIGHT) {
            p->bullets[i].alive = false;
        }
    }
}

