#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>

class GameMap
{
private:
    /* data */
protected:
    void DrawPlayerPosition(int PlayerX,int PlayerY);
public:
    bool bIsGameOver;
    MapCell Cells[15][10];
    MapCell* PlayerCell; 
    GameMap();
    ~GameMap();
    void DrawASCII(std::string Path);
    void Draw();
    void GetInitialPlayerPosition(int* InitialPositionX,int* InitialPositionY);
    bool SetPlayerCell(int PlayerX, int PlayerY);
    void LoadMapFromFile();
    void ClearScreen();
};

#endif // GAME_MAP_H