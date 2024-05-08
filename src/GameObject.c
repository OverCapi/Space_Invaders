#include <GameObject.h>
#include <TextureManager.h>

void init_object(struct GameObject *GameObject, SDL_Renderer *renderer, const char *filename, int x, int y, int w, int h)
{
    GameObject->object_texture = load_texture(renderer, filename);

    GameObject->x = x;
    GameObject->y = y;

    GameObject->w = w;
    GameObject->h = h;

    GameObject->src_rect.x = 0;
    GameObject->src_rect.y = 0;
    GameObject->src_rect.w = GameObject->w;
    GameObject->src_rect.h = GameObject->h;

    GameObject->dest_rect.x = GameObject->x;
    GameObject->dest_rect.y = GameObject->y;
    GameObject->dest_rect.w = GameObject->w;
    GameObject->dest_rect.h = GameObject->h;
}

void update_object(struct GameObject *GameObject, int x, int y, int w, int h)
{
    GameObject->x = x;
    GameObject->y = y;
    GameObject->w = w;
    GameObject->h = h;

    GameObject->src_rect.x = 0;
    GameObject->src_rect.y = 0;
    GameObject->src_rect.w = GameObject->w;
    GameObject->src_rect.h = GameObject->h;

    GameObject->dest_rect.x = x;
    GameObject->dest_rect.y = y;
    GameObject->dest_rect.w = w;
    GameObject->dest_rect.h = h;
}

void render_object(SDL_Renderer *renderer, struct GameObject GameObject)
{
    draw(renderer, GameObject.object_texture, GameObject.src_rect, GameObject.dest_rect);
}