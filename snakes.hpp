#include "game.hpp"
#include "tiles.hpp"
#include "game_type.hpp"
#include "dice.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class SnakesAndLadders : public Game{
protected:
    int snakeTiles,ladderTiles,snakePenalty,ladderReward,numPlayers,maxTurn,totalSpecialTiles,playerCounter,positionFinal;
    char tileCheck[1];
    vector<int> numsSnakesAndLadders;
    vector<Tile> totalTiles;
    vector<Player> players;
    Dice *d;
    GameType *gt;
public:
    SnakesAndLadders(Dice *d,GameType *gt);
    ~SnakesAndLadders();
    void start();
    void setBoardSize();
    void setSnakes();
    void setLadders();
    void setPenalty();
    void setReward();
    void setNumPlayers();
    void setNumTurns();
    void setGameType();
    void setAllInputs(SnakesAndLadders *g);
    void setPlayerTurn();
    void setSnakesAndLadders();
    void setBoard();
    void getBoard();
    void setListPlayers();
    void setPlayerPosition(int positionPlayer_,int tile_);
    int getPlayerPosition(int positionPlayer_);
    char getMovedName(SnakesAndLadders *g,int positionPlayer_,int randomNum);
    void setMovedPosition(int positionPlayer_,char tileType_[1]);
    void displayStatus(SnakesAndLadders *g);
    void buttonCheck(SnakesAndLadders *g);
    void endCheck(SnakesAndLadders *g);
};

//scope resolution
SnakesAndLadders::SnakesAndLadders(Dice *d,GameType *gt):d(new Dice()),gt(new GameType()){
    turn = 0;
    playerCounter = 1;
}
SnakesAndLadders::~SnakesAndLadders(){
    delete d;
    delete gt;
}
void SnakesAndLadders::start(){
    cout << "Press 'C' to continue next turn, or 'E' to end the game:" << endl;
}
void SnakesAndLadders::setBoardSize(){
    int tilesInput;
    while(cin >> tilesInput){
        if(tilesInput > 0){
            tiles = tilesInput;
            break;
        }
        else{
            cout << "Invalid input, number must be higher than 0\nNumber of tile in total: ";
            cin.clear();
        }
    }
}
void SnakesAndLadders::setSnakes(){
    int snakesInput;
    while(cin >> snakesInput){
        if(snakesInput > 0){
            snakeTiles = snakesInput;
            break;
        }
        else{
            cout << "Invalid input, number must be higher than 0\nNumber of snakes: ";
            cin.clear();        
        }
    }
}
void SnakesAndLadders::setLadders(){
    int laddersInput;
    while(cin >> laddersInput){
        if(laddersInput > 0){
            ladderTiles = laddersInput;
            break;
        }
        else{
            cout << "Invalid input, number must be higher than 0\nNumber of ladders: ";
            cin.clear(); 
        }
    }
}
void SnakesAndLadders::setPenalty(){
    int penaltyInput;
    while(cin >> penaltyInput){
        if(penaltyInput >= 0){
            snakePenalty = penaltyInput;
            break;
        }
        else{
            cout << "Invalid input, number must be higher than 0\nSnake penalty: ";
            cin.clear();  
        }
    }
}
void SnakesAndLadders::setReward(){
    int rewardInput;
    while(cin >> rewardInput){
        if(rewardInput > 0){
            ladderReward = rewardInput;
            break;
        }
        else{
            cout << "Invalid input, number must be higher than 0\nLadder reward: ";
            cin.clear();
        }
    }
}
void SnakesAndLadders::setNumPlayers(){
    int playersInput;
    while(cin >> playersInput){
        if(playersInput >= 2){
            numPlayers = playersInput;
            break;
        }
        else{
            cout << "Invalid input, number must be higher or equal to 2\nNumber of players: ";        
            cin.clear();
        }
    }
}
void SnakesAndLadders::setNumTurns(){
    int turnsInput;
    while(cin >> turnsInput){
        if(turnsInput > 0){
            maxTurn = turnsInput;
            break;
        }
        else{
            cout << "Invalid input, number must be higher than 0\nNumber of turns: ";        
            cin.clear();
        }
    }
}
void SnakesAndLadders::setGameType(){
    string gameTypeInput;
    while(cin >> gameTypeInput){
        if(gameTypeInput == "A" || gameTypeInput == "a"){
            gt->setGameType('A');
            break;
        }
        else if(gameTypeInput == "M" || gameTypeInput == "m"){
            gt->setGameType('M');
            break;
        }
        else if (typeid(gameTypeInput).name() != "string"){
            cout << "Invalid input, option must be either 'A' or 'M'\nGame type: ";
            cin.clear();
        }
    }
}
void SnakesAndLadders::setAllInputs(SnakesAndLadders *g){
    cout << "Number of tiles in total: ";
    g->setBoardSize();
    while(true){
        if(snakeTiles+ladderTiles <= tiles-4 && snakeTiles != 0 && ladderTiles != 0){
            break;
        }
        else if(snakeTiles == 0 && ladderTiles == 0){
            cout << "\nNumber of snakes: ";
            g->setSnakes();
            cout << "\nNumber of ladders: ";
            g->setLadders();
        }
        else{
            cout << "The total amount of snakes and ladders is too high, please try again" << endl;
            cout << "\nNumber of snakes: ";
            g->setSnakes();
            cout << "\nNumber of ladders: ";
            g->setLadders();
        }
    }
    cout << "\nSnake penalty: ";
    g->setPenalty();
    cout << "\nLadder reward: ";
    g->setReward();
    cout << "\nNumber of players: ";
    g->setNumPlayers();
    cout << "\nNumber of turns: ";
    g->setNumTurns();
    cout << "\nGame type: ";
    g->setGameType();
}
void SnakesAndLadders::setPlayerTurn(){
    if(playerCounter<numPlayers){
        playerNum = playerCounter;
        playerCounter++;
    }
    else if(playerCounter==numPlayers){
        playerNum = playerCounter;
        playerCounter = 1;
    }
}
void SnakesAndLadders::setSnakesAndLadders(){
    srand(time(NULL));
    totalSpecialTiles = snakeTiles + ladderTiles;
    numsSnakesAndLadders.reserve(totalSpecialTiles);
    for(int i=0;i<totalSpecialTiles;i++){
        int randomNumSL = d->getRandomNumTiles(tiles);
        while(find(numsSnakesAndLadders.begin(),numsSnakesAndLadders.end(),randomNumSL) != numsSnakesAndLadders.end()){
            randomNumSL = d->getRandomNumTiles(tiles);
        }
        numsSnakesAndLadders.push_back(randomNumSL);
    }
}
void SnakesAndLadders::setBoard(){
    totalTiles.reserve(tiles);
    for(int i=0;i<tiles;i++){
        if(find(numsSnakesAndLadders.begin(),numsSnakesAndLadders.end()-(totalSpecialTiles-snakeTiles),i) != numsSnakesAndLadders.end()-(totalSpecialTiles-snakeTiles)){
            totalTiles[i].setTileType('S');
        }
        else if(find(numsSnakesAndLadders.begin()+(snakeTiles),numsSnakesAndLadders.end(),i) != numsSnakesAndLadders.end()){
            totalTiles[i].setTileType('L');
        }
        else{
            totalTiles[i].setTileType('N');
        }
    }
}
void SnakesAndLadders::getBoard(){
    for(int i=0;i<tiles;i++){
        cout << totalTiles[i].getTileType() << " ";
    }
    cout << endl;
}
void SnakesAndLadders::setListPlayers(){
    players.reserve(numPlayers);
    players.assign(numPlayers,Player());
}
void SnakesAndLadders::setPlayerPosition(int positionPlayer_,int tile_){
    players[positionPlayer_-1].setSpace(tile_);
}
int SnakesAndLadders::getPlayerPosition(int positionPlayer_){
    return players[positionPlayer_-1].getSpace();
}
char SnakesAndLadders::getMovedName(SnakesAndLadders *g,int positionPlayer_,int randomNum){
    int position = g->getPlayerPosition(positionPlayer_);
    position += randomNum;
    if(position >= tiles){
        position = tiles - 1;
    }
    positionFinal = position;
    if(totalTiles[position].getTileType() == 'S'){
        tileCheck[0] = 'S';
        return 'S';
    }
    else if(totalTiles[position].getTileType() == 'L'){
        tileCheck[0] = 'L';
        return 'L';
    }
    else{
        tileCheck[0] = 'N';
        return 'N';
    }
}
void SnakesAndLadders::setMovedPosition(int positionPlayer_,char tileType_[1]){
    if(tileType_[0] == 'S'){
        positionFinal -= snakePenalty;
        if(positionFinal < 0){
            positionFinal = 0;
        }
        players[positionPlayer_-1].setSpace(positionFinal);
    }
    else if(tileType_[0] == 'L'){
        positionFinal += ladderReward;
        if(positionFinal >= tiles){
            positionFinal = tiles-1;
        }
        players[positionPlayer_-1].setSpace(positionFinal);
    }
    else{
        players[positionPlayer_-1].setSpace(positionFinal);
    }
}
void SnakesAndLadders::displayStatus(SnakesAndLadders *g){
    cout << "Turn: " << turn << " / Player: " << playerNum << " / Current tile: " << g->getPlayerPosition(playerNum) + 1;
    cout << " / Dice roll: " << d->getDiceRoll();
    cout << " / Landed tile name: " << g->getMovedName(g,playerNum,d->getDiceRoll());
    cout << " / Landed tile num: ";
    g->setMovedPosition(playerNum,tileCheck);
    cout << g->getPlayerPosition(playerNum) + 1 << endl;
    if(gt->getGameType() == 'A'){
        Sleep(1000);
    }
}
void SnakesAndLadders::buttonCheck(SnakesAndLadders *g){
    string input;
    if(gt->getGameType() == 'M'){
        if(turn == 1){
            g->start();
        }
        while(getline(cin,input)){
            if(input == "C" || input == "c"){
                break;
            }
            else if(input == "E" || input == "e"){
                cout << "-- GAME OVER --" << endl;
                cout << "Thanks for playing!!!" << endl;
                exit(0);
            }
            else{
                if(turn == 1){
                    break;
                }
                else{
                    cout << "Invalid option, please press 'C' to continue next turn or 'E' to end the game" << endl;
                }
            }
        }
    }
}
void SnakesAndLadders::endCheck(SnakesAndLadders *g){
    if(g->getPlayerPosition(playerNum) == tiles - 1){
        cout << "-- GAME OVER --" << endl;
        cout << "Player " << playerNum << " is the winner!!!" << endl;
        exit(0);
    }
    else if(turn == maxTurn){
        cout << "-- GAME OVER --" << endl;
        cout << "The maximum number of turns has been reached..." << endl;
        exit(0);
    }
}