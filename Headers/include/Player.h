#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    /* data */
protected:
    /* data */
public:
    int X,Y;
    int LastX,LastY;

    Player(int InitialPositionX,int InitialPositionY);
    ~Player();
    void CallInput();
    void ResetToSafePosition();
};

#endif // PLAYER_H