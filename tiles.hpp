#include <iostream>

using namespace std;

class Tile{
protected:
    char tileType[1];
public:
    Tile() = default;
    void setTileType(char tileType_);
    char getTileType();
};

void Tile::setTileType(char tileType_){
    tileType[0] = tileType_;
}
char Tile::getTileType(){
    return tileType[0];
}