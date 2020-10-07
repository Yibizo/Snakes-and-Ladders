#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Dice{
protected:
public:
    Dice() = default;
    int getRandomNumTiles(int tiles_);
    int getDiceRoll();
};

int Dice::getRandomNumTiles(int tiles_){
    int randomNum;
    randomNum = rand() % (tiles_-4) + 2;
    return randomNum;
}
int Dice::getDiceRoll(){
    int randomNumDice;
    srand((unsigned int)time(NULL)); //random seed everytime

    randomNumDice = rand() % 6 + 1; //num between 6 and 1
    return randomNumDice;
}