#include <Constant.h>
#include <Player.h>
#include <stdio.h>

void init_player(struct Player *player, SDL_Renderer *renderer)
{
    init_object(&player->player_object, renderer, "assets/pixel_ship_yellow.png", PLAYER_STARTPOS_X, PLAYER_STARTPOS_Y, PLAYER_WIDTH, PLAYER_HEIGHT);

    player->speed = PLAYER_SPEED;

    player->x = PLAYER_STARTPOS_X;
    player->y = PLAYER_STARTPOS_Y;

    player->up = FALSE;
    player->down = FALSE;
    player->right = FALSE;
    player->left = FALSE;
}

void update_player(struct Player *player, int x, int y)
{
    update_object(&player->player_object, x, y, PLAYER_WIDTH, PLAYER_HEIGHT);
}

void render_player(struct Player *player, SDL_Renderer* renderer)
{
    render_object(renderer, player->player_object);
}

void move_up(struct Player *player, float delta_time)
{
    if (player->y - player->speed * delta_time > 0)
    {
        player->y -= player->speed * delta_time; 
        update_player(player, player->x, player->y);
    }
}

void move_down(struct Player *player, float delta_time)
{
    if (player->y + player->speed * delta_time < PLAYER_BORDER_BOTTOM)
    {
        player->y += player->speed * delta_time; 
        update_player(player, player->x, player->y);
    }
}

void move_right(struct Player *player, float delta_time)
{
    if (BORDER_MODE == TRUE)
    {
        // BORDER MODE
        if (player->x + player->speed * delta_time < PLAYER_BORDER_RIGHT)
        {
            player->x += player->speed * delta_time; 
            update_player(player, player->x, player->y);
        }
    }
    else
    {
        // BORDERLESS MODE
        player->x += player->speed * delta_time; 
        if (player->x > SCREEN_WIDTH)
        {
            player->x = -100;
            update_player(player, player->x, player->y);
        }
        else
            update_player(player, player->x, player->y);
    }
}

void move_left(struct Player *player, float delta_time)
{
    if (BORDER_MODE == TRUE)
    {
        if (player->x - player->speed * delta_time > 0)
        {
            player->x -= player->speed * delta_time; 
            update_player(player, player->x, player->y);
        }
    }
    else
    {
        if (player->x < -100)
        {
            player->x = SCREEN_WIDTH + PLAYER_WIDTH;
            update_player(player, player->x, player->y);
        }
        else
            update_player(player, player->x, player->y);
            player->x -= player->speed * delta_time; 
    }
}

void move_player(struct Player *player, float delta_time)
{
    if (player->up)
        move_up(player, delta_time);
    if (player->down)
        move_down(player, delta_time);
    if (player->right)
        move_right(player, delta_time);
    if (player->left)
        move_left(player, delta_time);
}