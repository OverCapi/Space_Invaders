#include <Player.h>
#include <stdio.h>

void init_player(struct Player *player, SDL_Renderer *renderer)
{
    init_object(&player->player_object, renderer, PLAYER_TEXTURE_FILE, PLAYER_STARTPOS_X, PLAYER_STARTPOS_Y, PLAYER_WIDTH, PLAYER_HEIGHT);

    player->speed = PLAYER_SPEED;

    player->x = PLAYER_STARTPOS_X;
    player->y = PLAYER_STARTPOS_Y;

    player->up = FALSE;
    player->down = FALSE;
    player->right = FALSE;
    player->left = FALSE;

    player->is_shooting = FALSE;
    player->last_frame_time_shoot = 0;
    player->projectile_count = 0;
}

void update_player_coords(struct Player *player, int x, int y)
{
    update_object(&player->player_object, x, y, PLAYER_WIDTH, PLAYER_HEIGHT);
}

void render_player(struct Player *player, SDL_Renderer* renderer)
{
    int i;
    int nbr = 0;
    render_object(renderer, player->player_object);
    for ( i = 0; i <= player->projectile_count; i++)
    {
        if ((player->Projectiles[i].x > 0 && player->Projectiles[i].x < SCREEN_WIDTH) && player->Projectiles[i].y > -PROJECTILE_HEIGHT)
        {
            render_projectile(&player->Projectiles[i], renderer);
        }
    }
}

void player_shoot(struct Player *player, SDL_Renderer *renderer)
{
    int i;
    if (player->is_shooting == TRUE && SDL_GetTicks() - player->last_frame_time_shoot > PLAYER_COOLDOWN_SHOOT)
    {
        player->projectile_count++;

        if (player->projectile_count > PROJECTILE_MAX_COUNT - 1)
        {
            player->projectile_count = 1;
        }

        int projectile_x = player->x + PLAYER_WIDTH / 2 - PROJECTILE_WIDTH / 2;
        int projectile_y = player->y - PROJECTILE_HEIGHT / 2;

        init_projectile(&player->Projectiles[player->projectile_count], renderer, projectile_x, projectile_y);

        player->last_frame_time_shoot = SDL_GetTicks();
        player->is_shooting = FALSE;
    }
}

void move_up(struct Player *player, float delta_time)
{
    if (player->y - player->speed * delta_time > 0)
    {
        player->y -= player->speed * delta_time; 
        update_player_coords(player, player->x, player->y);
    }
}

void move_down(struct Player *player, float delta_time)
{
    if (player->y + player->speed * delta_time < PLAYER_BORDER_BOTTOM)
    {
        player->y += player->speed * delta_time; 
        update_player_coords(player, player->x, player->y);
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
            update_player_coords(player, player->x, player->y);
        }
    }
    else
    {
        // BORDERLESS MODE
        player->x += player->speed * delta_time; 
        if (player->x > SCREEN_WIDTH)
        {
            player->x = -PLAYER_WIDTH;
            update_player_coords(player, player->x, player->y);
        }
        else
            update_player_coords(player, player->x, player->y);
    }
}

void move_left(struct Player *player, float delta_time)
{
    if (BORDER_MODE == TRUE)
    {
        if (player->x - player->speed * delta_time > 0)
        {
            player->x -= (int)(player->speed * delta_time); 
            update_player_coords(player, player->x, player->y);
        }
    }
    else
    {
        if (player->x < -100)
        {
            player->x = (int)(SCREEN_WIDTH + PLAYER_WIDTH / 2);
            update_player_coords(player, player->x, player->y);
        }
        else
            update_player_coords(player, player->x, player->y);
            player->x -= player->speed * delta_time; 
    }
}

void move_player(struct Player *player, float delta_time)
{
    if (player->up && !player->down)
        move_up(player, delta_time);
    if (player->down && !player->up)
        move_down(player, delta_time);
    if (player->right && !player->left)
        move_right(player, delta_time);
    if (player->left && !player->right)
        move_left(player, delta_time);
}

void update_player(struct Player *player, SDL_Renderer *renderer, float delta_time)
{
    int i;
    move_player(player, delta_time);
    player_shoot(player, renderer);
    for ( i = 0; i <= player->projectile_count; i++)
    {
        update_projectile(&player->Projectiles[i], delta_time);
    }
}