#ifndef Projectile_H
#define Projectile_H

#include <GameObject.h>

struct Projectile
{
    struct GameObject projectile_object;
    int x;
    int y;
    float speed;
};

void init_projectile(struct Projectile *projectile, SDL_Renderer *renderer, int x, int y);
void update_projectile(struct Projectile *projectile, float delta_time);
void render_projectile(struct Projectile *projectile, SDL_Renderer *renderer);

#endif