#ifndef GAME_MAP_H
#define GAME_MAP_H

class GameMap
{
private:
    /* data */
protected:
    void DrawPlayerPosition(int PlayerX,int PlayerY);
public:
    MapCell Cells[15][10];
    MapCell* PlayerCell; 
    GameMap();
    ~GameMap();
    void DrawIntro();
    void Draw();
    void GetInitialPlayerPosition(int* InitialPositionX,int* InitialPositionY);
    bool SetPlayerCell(int PlayerX, int PlayerY);
    void LoadMapFromFile();
    void ClearScreen();
};

#endif // GAME_MAP_H