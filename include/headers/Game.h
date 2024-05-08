#ifndef Game_H
#define Game_H

#include <Constant.h>
#include <SDL.h>
#include <SDL_image.h>

struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;

    int game_state;
    int last_frame_time;
    int update_count;
};

int init_game(void);

void setup(void);
void game_loop(void);
void run(void);

#endif