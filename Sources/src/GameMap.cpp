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
    for(int i = 0; i < 15; i = i + 1){
        for (int j = 0; j < 10; j++){

            switch (Cells[i][j].ID )
            {
            case '0':
                std::cout << '\0';
                break;
            case '1':
                std::cout << '|';
                break;
            default:
                std::cout << Cells[i][j].ID ;
                break;
            }
        }

        std::cout << std::endl;
    }
}

void GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    ClearScreen();

    if (PlayerCell != NULL){
        PlayerCell->ID = 0;
    }
    
    PlayerCell = &Cells[PlayerY][PlayerX];
    PlayerCell->ID = '*';

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

            for (int p = 0; p < Line.length(); p++){
                Cells[Row][p].ID = Line[p];
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
