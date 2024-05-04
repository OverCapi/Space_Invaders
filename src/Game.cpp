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
            printf("Window created!...\n");
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer != NULL)
        {
            printf("Renderer created!...\n");
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
        case SDL_QUIT:
            gameState = false;
    }
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf("Game cleaned!...\n");
}

bool Game::is_running()
{
    return gameState;
}
