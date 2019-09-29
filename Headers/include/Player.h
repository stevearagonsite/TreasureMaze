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

    Player(/* args */);
    ~Player();
    void CallInput();
    void ResetToSafePosition();
};

#endif // PLAYER_H