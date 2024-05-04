#pragma once

#include <Game.h>

class GameObject
{
    public:
        int objXPos;
        int objYPos;
        int objWidth;
        int objHeight;

        GameObject(const char *filename);
        ~GameObject();

        void update(int xpos, int ypos, int w, int h);
        void render();

    private:
        SDL_Texture* objTexture = nullptr;
        SDL_Rect srcRect, destRect;
};