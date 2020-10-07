#include <iostream>

using namespace std;

class Player{
protected:
    int space;
public:
    Player();
    void setSpace(int space);
    int getSpace();
};

Player::Player(){
        space = 0;
    }
void Player::setSpace(int space_){
        space = space_;
    }
int Player::getSpace(){
        return space;
    }