#pragma once

#include <GameObject.h>

class Player
{
    public:
        Player();
        ~Player();

        bool go_Up = false;
        bool go_Down = false;
        bool go_Left = false;
        bool go_Right = false;

        void init(int xpos, int ypos);
        void render();
        void update(int xpos, int ypos);
        void move();

    private:
        GameObject* objPlayer;

        int maxHealth = 100;
        int health = 100;

        int move_speed = 20;

        int x;
        int y;

        int width = 50;
        int height = 45;

        void move_Down();
        void move_Up();
        void move_Right();
        void move_Left();
};