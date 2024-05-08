#ifndef Player_H
#define Player_H

#include <GameObject.h>

struct Player {
    struct GameObject player_object;
    float x;
    float y;
    float speed;

    int up;
    int down;
    int left;
    int right;
};

void init_player(struct Player *Player, SDL_Renderer *renderer);
void update_player(struct Player *player, int x, int y);
void render_player(struct Player *player, SDL_Renderer* renderer);
void move_player(struct Player *player, float delta_time);

#endif