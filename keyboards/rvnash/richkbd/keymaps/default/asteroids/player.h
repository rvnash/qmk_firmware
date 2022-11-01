
//player.h

#include "vector.h"

#define P_VERTS 3
#define BULLETS 3

struct bullet {

    struct vector2d location;
    struct vector2d velocity;
    bool alive;
};

struct player {

    float hit_radius;
    int lives;
    bool alive;
    int exploding_time;
    struct vector2d location;
    struct vector2d velocity;
    struct vector2d obj_vert[P_VERTS];
    struct vector2d world_vert[P_VERTS];
    struct bullet bullets[BULLETS];
};

void init_player(struct player* p);

void draw_player(struct player* p);

void shoot_bullet(struct player* p);

void update_player(struct player* p);

void bounds_player(struct player* p);

void apply_force(struct vector2d* velocity, struct vector2d v);

void rotate_player(struct player* p, float degrees);

struct vector2d get_direction(struct player* p);

