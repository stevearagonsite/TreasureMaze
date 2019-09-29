#include "../../Headers/include/Player.h"
#include <iostream>

Player::Player()
{
    X = 0;
    Y = 0;
}

Player::~Player()
{
}

void Player::CallInput()
{
    char UserInput = ' ';
    std::cin >> UserInput;

    switch (UserInput)
    {
    case 'w':
        --Y;
        break;
    case 's':
        ++Y;
        break;
    case 'a':
        --X;
        break;
    case 'd':
        ++X;
        break;
    default:
        break;
    }

}
