#include "snakes.hpp"
#include <iostream>

using namespace std;

int main(){
    Dice *d = new Dice();
    GameType *gt = new GameType();
    SnakesAndLadders *g = new SnakesAndLadders(d,gt);
    g->setAllInputs(g);
    g->setSnakesAndLadders();
    g->setBoard();
    //g->getBoard();
    g->setListPlayers();
    while(true){
        g->plusTurn();
        g->setPlayerTurn();
        g->buttonCheck(g);
        g->displayStatus(g);
        g->endCheck(g);
    }
    delete g;

    return 0;
}