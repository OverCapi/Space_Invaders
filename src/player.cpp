#include <Player.h>

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