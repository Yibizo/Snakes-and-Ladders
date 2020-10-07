#include <iostream>

using namespace std;

class GameType{
protected:
    char gameType[1];
public:
    GameType() = default;
    void setGameType(char gameType_);
    char getGameType();
};

void GameType::setGameType(char gameType_){
    gameType[0] = gameType_;
}
char GameType::getGameType(){
    return gameType[0];
}