#ifndef GAME_MAP_H
#define GAME_MAP_H

class GameMap
{
private:
    /* data */
protected:
    /* data */
public:
    MapCell Cells[15][10];
    MapCell* PlayerCell; 
    GameMap(/* args */);
    ~GameMap();
    void Draw();
    void SetPlayerCell(int PlayerX, int PlayerY);
    void LoadMapFromFile();
    void ClearScreen();
};

#endif // GAME_MAP_H