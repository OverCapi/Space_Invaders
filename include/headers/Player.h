#ifndef Player_H
#define Player_H

#include <GameObject.h>
#include <Projectile.h>
#include <Constant.h>

struct Player {
    struct GameObject player_object;
    int x;
    int y;
    float speed;

    int up;
    int down;
    int left;
    int right;

    int last_frame_time_shoot;
    int is_shooting;
    struct Projectile Projectiles[PROJECTILE_MAX_COUNT];
    int projectile_count;
};

void init_player(struct Player *Player, SDL_Renderer *renderer);
void update_player(struct Player *player, SDL_Renderer *renderer, float delta_time);
void render_player(struct Player *player, SDL_Renderer* renderer);

#endif