#include <Projectile.h>
#include <Constant.h>
#include <stdio.h>

void init_projectile(struct Projectile *projectile, SDL_Renderer *renderer, int x, int y)
{
    projectile->x = x;
    projectile->y = y;
    projectile->speed = PROJECTILE_SPEED;
    init_object(&projectile->projectile_object, renderer, PROJECTILE_TECTURE_FILE, projectile->x, projectile->y, PROJECTILE_WIDTH, PROJECTILE_HEIGHT);
}

void update_projectile(struct Projectile *projectile, float delta_time)
{
    projectile->y -= projectile->speed * delta_time;
    update_object(&projectile->projectile_object, projectile->x, projectile->y, PROJECTILE_WIDTH, PROJECTILE_HEIGHT);
}

void render_projectile(struct Projectile *projectile, SDL_Renderer *renderer)
{
    render_object(renderer, projectile->projectile_object);
}