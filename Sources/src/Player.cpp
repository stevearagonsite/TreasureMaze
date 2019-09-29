#include "../../Headers/include/Player.h"
#include <iostream>

Player::Player(int InitialPositionX,int InitialPositionY)
{
    X = InitialPositionX;
    Y = InitialPositionY;
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
        LastY = Y;
        --Y;
        break;
    case 's':
        LastY = Y;
        ++Y;
        break;
    case 'a':
        LastX = X;
        --X;
        break;
    case 'd':
        LastX = X;
        ++X;
        break;
    default:
        break;
    }
}

void Player::ResetToSafePosition()
{
    X = LastX;
    Y = LastY;
}
