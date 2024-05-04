#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <stdio.h>

class Game
{
    public:
        Game();
        ~Game();

        void init(const char *title, int x, int y, int w, int h, Uint32 flags);

        void run(const int FPS);

    private:

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;

        int screen_width = 1024;
        int screen_height = 600;
        int update_count = 0;

        bool gameState = false;

        void update();
        void render();
        void clean();
        void handleEvents();

        bool is_running();
};

#endif