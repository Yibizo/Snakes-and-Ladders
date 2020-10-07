#include "player.hpp"
#include <iostream>

using namespace std;

class Game{
protected:
    int turn,playerNum,tiles;
public:
    Game() = default;
    void plusTurn();
    int getPlayerNum();
    virtual void setPlayerTurn(){
    if(turn % 2 != 0){
        playerNum = 1;
    }
    else if(turn %2 == 0){
        playerNum = 2;
    }
}
}; 

void Game::plusTurn(){
    turn ++;
}
int Game::getPlayerNum(){
    return playerNum;
}