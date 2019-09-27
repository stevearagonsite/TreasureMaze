#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    /* data */
protected:
    int x,y;
public:
    Player(/* args */);
    ~Player();
    void CallInput();
};

#endif // PLAYER_H