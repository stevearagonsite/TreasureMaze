#include "../../Headers/include/Player.h"
#include <iostream>

Player::Player()
{
    x = 1;
    y = 1;
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
        ++y;
        std::cout << "The player go to up \n";
        break;
    case 's':
        system ("CLS");
        --y;
        std::cout << "The player go to down \n";
        break;
    case 'a':
        system ("CLS");
        --x;
        std::cout << "The player go to left \n";
        break;
    case 'd':
        system ("CLS");
        ++x;
        std::cout << "The player go to right \n";
        break;
    default:
        system ("CLS");
        std::cout << "\n";
        break;
    }
    
    std::cout << "==========================\n";
    std::cout << "---->  MY PLAYER IS  <----\n";
    std::cout << "\tx: "<< x << "; y: " << y << ";\n";
    std::cout << "==========================\n\n\n";

}
