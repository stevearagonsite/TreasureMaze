#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "../../Headers/include/GameMap.h"

GameMap::GameMap()
{
    PlayerCell = NULL;
    bIsGameOver = false;
}

GameMap::~GameMap()
{
}

void GameMap::GetInitialPlayerPosition(int* InitialPositionX,int* InitialPositionY){
    int CountY = 0;
    std::string Line = "";
    std::ifstream MyFile("./Map.txt");

    if (MyFile.is_open()){
        while (getline(MyFile, Line,'\n')){

            for (int CountX = 0; CountX < Line.length(); ++CountX){
                if(Line[CountX] == '2'){
                    *InitialPositionX = CountX;
                    *InitialPositionY = CountY;
                    return;
                }
            }
            ++CountY;
        }
        std::cout << "FATAL ERROR: MAP FILE HAS NOT INITIAL POSITION! \n";
    }else{
        std::cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED! \n";
    }
}

void GameMap::DrawASCII(std::string Path)
{
    std::string Line = "";
    std::ifstream MyFile(Path);

    if (MyFile.is_open()){
        while (getline(MyFile, Line)){
            std::cout << Line << '\n';
        }
        std::cout << "\n\n\n";
    }else{
        std::cout << "FATAL ERROR: PATH FILE COULD NOT BE LOADED! \n";
    }
}

void GameMap::Draw()
{
    for(int FirstCount = 0; FirstCount < 15; ++FirstCount){
        for (int SecondCount = 0; SecondCount < 10; ++SecondCount){

            switch (Cells[FirstCount][SecondCount].ID )
            {
            case '0': // Empty
                std::cout << '\0';
                break;
            case '1': // Wall
                std::cout << '|';
                break;
            case '2': // Initial position
                std::cout << '\0';
                break;
            case '3': // Treasure
                std::cout << '$';
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
    if (Cells[PlayerY][PlayerX].ID == '3'){
        ClearScreen();

        DrawASCII("./Victory.txt");
        bIsGameOver = true;
        return true;
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
