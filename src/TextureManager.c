#include <TextureManager.h>

SDL_Texture* load_texture(SDL_Renderer *renderer, const char *filename)
{
    SDL_Surface *tempSuface = IMG_Load(filename);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSuface);
    SDL_FreeSurface(tempSuface);
    return texture;
}

void draw(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect src_Rect, SDL_Rect dest_Rect)
{
    SDL_RenderCopy(renderer, texture, &src_Rect, &dest_Rect);
}