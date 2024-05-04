#include <stdio.h>
#include <Game.h>

Game* game = nullptr;

int main(int argc, char **argv)
{
    const int FPS = 60;

    game = new Game();

    game->init("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 600, SDL_WINDOW_SHOWN);

    game->run(FPS);

    return 0;
}