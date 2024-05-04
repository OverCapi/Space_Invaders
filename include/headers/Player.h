#pragma once

#include <GameObject.h>

class Player
{
    public:
        Player();
        ~Player();

        void init(int xpos, int ypos);
        void render();
        void update(int xpos, int ypos);

    private:
        GameObject* objPlayer;

        int maxHealth = 100;
        int health = 100;

        int x;
        int y;

        int width = 50;
        int height = 45;
};