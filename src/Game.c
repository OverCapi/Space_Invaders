#include <stdio.h>
#include <GameObject.h>
#include <Player.h>
#include <Game.h>

struct Game Game = {
    .window = NULL,
    .renderer = NULL,
    .game_state = FALSE,
    .last_frame_time = 0,
    .update_count = 0
};

struct GameObject background;
struct Player player;

int init_game(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error : Initializing SDL!...\n");
        return FALSE;
    }
    Game.window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);
    if (!Game.window)
    {
        printf("Error : Creating SDL Window!...\n");
        return FALSE;
    }
    Game.renderer = SDL_CreateRenderer(Game.window, -1, 0);
    if (!Game.renderer)
    {
        printf("Error : Creating SDL Renderer!...\n");
        return FALSE;
    }
    return TRUE;
}

void clean(void)
{
    SDL_DestroyRenderer(Game.renderer);
    SDL_DestroyWindow(Game.window);
    SDL_Quit();
    printf("Game cleaned!...\n");
}

void setup(void) 
{
    init_object(&background, Game.renderer, "assets/background-black.png", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    init_player(&player, Game.renderer);
}

void key_down_event(SDL_Event *event)
{
    if (event->key.keysym.sym == SDLK_SPACE)
        player.is_shooting = TRUE;
    if (event->key.keysym.sym == SDLK_UP)
        player.up = TRUE;
    if (event->key.keysym.sym == SDLK_DOWN)
        player.down = TRUE;
    if (event->key.keysym.sym == SDLK_RIGHT)
        player.right = TRUE;
    if (event->key.keysym.sym == SDLK_LEFT)
        player.left = TRUE;
}

void key_up_event(SDL_Event *event)
{
    if (event->key.keysym.sym == SDLK_SPACE)
        player.is_shooting = FALSE;
    if (event->key.keysym.sym == SDLK_UP)
        player.up = FALSE;
    if (event->key.keysym.sym == SDLK_DOWN)
        player.down = FALSE;
    if (event->key.keysym.sym == SDLK_RIGHT)
        player.right = FALSE;
    if (event->key.keysym.sym == SDLK_LEFT)
        player.left = FALSE;
}

void handleEvents(void)
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                Game.game_state = FALSE;
            else
                key_down_event(&event);
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                Game.game_state = FALSE;
            else
                key_up_event(&event);
            break;
        case SDL_QUIT:
            Game.game_state = FALSE;
            break;
        default:
            break;
    }
}

void update(void)
{
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - Game.last_frame_time);
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
        SDL_Delay(time_to_wait);

    Game.update_count++;

    float delta_time = (SDL_GetTicks() - Game.last_frame_time) / 1000.0f;

    update_player(&player, Game.renderer, delta_time);
    
    Game.last_frame_time = SDL_GetTicks();
}

void render(void)
{
    SDL_RenderClear(Game.renderer);

    render_object(Game.renderer, background);
    render_player(&player, Game.renderer);

    SDL_RenderPresent(Game.renderer);
}

void game_loop(void)
{
    while (Game.game_state)
    {
        handleEvents();
        update();
        render();
    }
    clean();
}

void run(void)
{
    Game.game_state = init_game();
    if (Game.game_state)
    {
        printf("\nBORDER MODE : %d\n", BORDER_MODE);
        setup();
        game_loop();
    }
}