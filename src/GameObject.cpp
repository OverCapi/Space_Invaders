#include <TextureManager.h>
#include <GameObject.h>

GameObject::GameObject(const char *filename)
{
    objTexture = TextureManager::LoadTexture(filename);
}

GameObject::~GameObject()
{

}

void GameObject::update(int xpos, int ypos, int w, int h)
{
    objXPos = xpos;
    objYPos = ypos;
    objWidth = w;
    objHeight = h;

    srcRect.x = srcRect.y = 0;
    srcRect.w = objWidth;
    srcRect.h = objHeight;

    destRect.x = objXPos;
    destRect.y = objYPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}