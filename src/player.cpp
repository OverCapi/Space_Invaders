#include <Player.h>
#include <iostream>

Player::Player()
{

}

Player::~Player()
{

}

void Player::init(int xpos, int ypos)
{
    objPlayer = new GameObject("assets/pixel_ship_yellow.png");
    x = xpos;
    y = ypos;
    update(x, y);
}

void Player::render()
{
    objPlayer->render();
}

void Player::update(int xpos, int ypos)
{
    x = xpos;
    y = ypos;
    objPlayer->update(x, y, width, height);
}

void Player::Player::move()
{
    if (go_Down == true)
    {
        move_Down();
        go_Down = false;
    }
    else if (go_Up == true)
    {
        move_Up();
        go_Up = false;
    }
    else if (go_Right == true)
    {
        move_Right();
        go_Right = false;
    }
    else if (go_Left == true)
    {
        move_Left();
        go_Left = false;
    }
}

void Player::move_Down()
{
    if (y + move_speed < 1000)
        update(x, y + move_speed);
}

void Player::move_Up()
{
    if (y - move_speed > 0)
        update(x, y - move_speed);
}

void Player::move_Right()
{
    if (x + move_speed < 1000)
        update(x + move_speed, y);
}

void Player::move_Left()
{
    if (x - move_speed > 0)
        update(x - move_speed, y);
}