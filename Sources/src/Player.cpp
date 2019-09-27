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
        system ("CLS");
        --Y;
        std::cout << "The player go to up \n";
        break;
    case 's':
        system ("CLS");
        ++Y;
        std::cout << "The player go to down \n";
        break;
    case 'a':
        system ("CLS");
        --X;
        std::cout << "The player go to left \n";
        break;
    case 'd':
        system ("CLS");
        ++X;
        std::cout << "The player go to right \n";
        break;
    default:
        system ("CLS");
        std::cout << "\n";
        break;
    }

}
