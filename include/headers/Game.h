#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Game
{
    public:
        Game();
        ~Game();

        static SDL_Renderer* renderer;

        void init(const char *title, int x, int y, int w, int h, Uint32 flags);

        void run(const int FPS);

        void key_down_event(SDL_Event* event);
        void key_up_event(SDL_Event* event);

    private:

        SDL_Window* window = nullptr;

        int screen_width = 1000;
        int screen_height = 1000;

        int update_count = 0;

        bool gameState = false;

        void update();
        void render();
        void clean();
        void handleEvents();

        bool is_running();
};

#endif