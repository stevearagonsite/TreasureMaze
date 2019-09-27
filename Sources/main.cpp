#include <iostream>

#include "../Headers/include/Player.h"
#include "./src/Player.cpp"
#include "../Headers/include/MapCell.h"
#include "./src/MapCell.cpp"
#include "../Headers/include/GameMap.h"
#include "./src/GameMap.cpp"

int main(){
    bool bIsGameOver = false;
    Player Hero;
    GameMap Map;
    system ("CLS");
    std::cout << "Welcome to the treause maze!! \n\n\n";
    std::cout << "Press any key to continue...";
    std::cin;

    while (!bIsGameOver){
        Hero.CallInput();
        Map.Draw();
        std::cout << "Your input: ";
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discard the buffer
    }
    return 0;
}