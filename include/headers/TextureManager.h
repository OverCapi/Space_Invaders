#ifndef TextureManager_H
#define TextureManager_H

#include <SDL.h>
#include <SDL_image.h>

SDL_Texture* load_texture(SDL_Renderer *renderer, const char *filename);
void draw(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect src_Rect, SDL_Rect dest_Rect);

#endif