#include <iostream>

#include <Game.h>
#include <Player.h>
#include <GameObject.h>

SDL_Renderer* Game::renderer = nullptr;
Player* player = nullptr;
GameObject* background = nullptr;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char *title, int x, int y, int w, int h, Uint32 flags)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        screen_width = w;
        screen_height = h;

        window = SDL_CreateWindow(title, x, y, screen_width, screen_height, flags);
        if (window != NULL)
        {
            std::cout << "Window created!..." << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer != NULL)
        {
            std::cout << "Renderer created!..." << std::endl;
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            gameState = true;
        }
        player = new Player();
        player->init(450, 850);

        background = new GameObject("assets/background-black.png");
        background->update(0, 0, 1000, 1000);
    }
}

void Game::run(const int FPS)
{
    const int frameRate = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    while (is_running())
    {
        frameStart = SDL_GetTicks();

        handleEvents();
        update();
        render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameRate > frameTime)
        {
            SDL_Delay(frameRate - frameTime);
        }
    }
    clean();
}

void Game::update()
{
    update_count++;
    //std::cout << update_count << std::endl;
    player->move();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    background->render();
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_KEYDOWN:
            key_down_event(&event);
            break;
        case SDL_KEYUP:
            key_up_event(&event);
            break;
        case SDL_QUIT:
            gameState = false;
            break;
    }
}

void Game::key_down_event(SDL_Event* event)
{
    switch (event->key.keysym.sym)
    {
        case SDLK_UP:
            player->go_Up = true;
            break;
        case SDLK_DOWN:
            player->go_Down = true;
            break;
        case SDLK_RIGHT:
            player->go_Right = true;
            break;
        case SDLK_LEFT:
            player->go_Left = true;
            break;
    }
}

void Game::key_up_event(SDL_Event* event)
{
    switch (event->key.keysym.sym)
    {
        case SDLK_UP:
            player->go_Up = false;
            break;
        case SDLK_DOWN:
            player->go_Down = false;
            break;
        case SDLK_RIGHT:
            player->go_Right = false;
            break;
        case SDLK_LEFT:
            player->go_Left = false;
            break;
    }
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!..." << std::endl;
}

bool Game::is_running()
{
    return gameState;
}
