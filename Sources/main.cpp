#include <iostream>
#include <windows.h> // WinApi header 

#include "../Headers/include/Player.h"
#include "./src/Player.cpp"
#include "../Headers/include/MapCell.h"
#include "./src/MapCell.cpp"
#include "../Headers/include/GameMap.h"
#include "./src/GameMap.cpp"

int main(){
    bool bIsGameOver = false;
    GameMap Map;
    Map.ClearScreen();
    Map.DrawIntro();
    std::cout << '\a'; //sound inital
    std::cout << "Welcome to the treause maze!! \n";
    std::cout << "Press any key to continue...";
    std::cin;
    int InitialPositionX, InitialPositionY;
    Map.GetInitialPlayerPosition(&InitialPositionX, &InitialPositionY);
    Player Hero(InitialPositionX, InitialPositionY);

    while (!bIsGameOver){
        std::cout << "Enter the move command \'W\' \'A\' \'S\' \'D\' \n";
        Hero.CallInput();
        Map.LoadMapFromFile();

        if (Map.SetPlayerCell(Hero.X, Hero.Y)){
            Map.Draw();
        }else{
            Hero.ResetToSafePosition();
            Map.SetPlayerCell(Hero.X, Hero.Y);
            Map.Draw();
        }
        
        Beep(523,500);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discard the buffer
    }
    return 0;
}