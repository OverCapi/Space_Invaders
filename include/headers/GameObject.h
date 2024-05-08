#ifndef GameObject_H
#define GameObject_H

#include <SDL.h>
#include <SDL_image.h>

struct GameObject {
    SDL_Texture *object_texture;
    SDL_Rect src_rect;
    SDL_Rect dest_rect;

    int x;
    int y;
    int w;
    int h;
};

void init_object(struct GameObject *GameObject, SDL_Renderer *renderer, const char *filename, int x, int y, int w, int h);

void update_object(struct GameObject *GameObject, int x, int y, int w, int h);

void render_object(SDL_Renderer *renderer, struct GameObject GameObject);

#endif