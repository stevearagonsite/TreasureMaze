#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "./MapCell.h";

class GameMap
{
private:
    /* data */
protected:
    /* data */
public:
    GameMap(/* args */);
    ~GameMap();
    MapCell Cells[15][10]; 
    void Draw();
};

#endif // GAME_MAP_H