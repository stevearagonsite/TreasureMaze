#include <iostream>
#include "../Headers/include/Player.h"
#include "./src/Player.cpp"

int main(){
    bool bIsGameOver = false;
    Player Hero;
    
    system ("CLS");
    std::cout << "Welcome to the treause maze!! \n\n\n";
    std::cout << "Press any key to continue...";
    std::cin;

    while (!bIsGameOver){
        Hero.CallInput();
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discard the buffer
    }
    return 0;
}