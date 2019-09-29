#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "../../Headers/include/GameMap.h"

GameMap::GameMap(/* args */)
{
    PlayerCell = NULL;
}

GameMap::~GameMap()
{
}

void GameMap::Draw()
{
    for(int FirstCount = 0; FirstCount < 15; ++FirstCount){
        for (int SecondCount = 0; SecondCount < 10; ++SecondCount){

            switch (Cells[FirstCount][SecondCount].ID )
            {
            case '0':
                std::cout << '\0';
                break;
            case '1':
                std::cout << '|';
                break;
            default:
                std::cout << Cells[FirstCount][SecondCount].ID ;
                break;
            }
        }

        std::cout << std::endl;
    }
}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    if (Cells[PlayerY][PlayerX].IsBlocked()){
        return false;
    }
    
    ClearScreen();
    if (PlayerCell != NULL){
        PlayerCell->ID = 0;
    }

    PlayerCell = &Cells[PlayerY][PlayerX];
    PlayerCell->ID = '*';
    DrawPlayerPosition(PlayerX, PlayerY);
    return true;
}

void GameMap::DrawPlayerPosition(int PlayerX,int PlayerY){
    std::cout << "==========================\n";
    std::cout << "---->  MY PLAYER IS  <----\n";
    std::cout << "\tx: "<< PlayerX << "; y: " << PlayerY << ";\n";
    std::cout << "==========================\n\n";
}

void GameMap::LoadMapFromFile()
{
    // Create the file!
    // std::ofstream FileCreated("./Map.txt");

    int Row = 0;
    std::string Line = "";
    std::ifstream MyFile("./Map.txt");

    if (MyFile.is_open()){
        while (getline(MyFile, Line,'\n')){

            for (int Count = 0; Count < Line.length(); ++Count){
                Cells[Row][Count].ID = Line[Count];
            }
            ++Row;
        }
    }else{
        std::cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED! \n";
    }
}

void GameMap::ClearScreen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("cls");
#endif
}
