#include "../../Headers/include/GameMap.h"
#include <iostream>

GameMap::GameMap(/* args */)
{
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