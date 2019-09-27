#include "../../Headers/include/GameMap.h"
#include <iostream>

GameMap::GameMap(/* args */)
{
    PlayerCell = NULL;
}

GameMap::~GameMap()
{
}

void GameMap::Draw()
{
    for(int i = 0; i < 15; i = i + 1){
        for (int j = 0; j < 10; j++){
            std::cout << Cells[i][j].ID;
        }

        std::cout << std::endl;
    }
}

void GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    if (PlayerCell != NULL){
        PlayerCell->ID = 0;
    }
    
    PlayerCell = &Cells[PlayerY][PlayerX];
    PlayerCell->ID = 1;

    std::cout << "==========================\n";
    std::cout << "---->  MY PLAYER IS  <----\n";
    std::cout << "\tx: "<< PlayerX << "; y: " << PlayerY << ";\n";
    std::cout << "==========================\n\n";
}