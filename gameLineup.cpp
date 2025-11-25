#include "gameLineup.hpp"
gameLineup::gameLineup(string gameLineupId, Date date, int gameId, int playerId, int clubId, 
        string playerName, string type, string position, int number){
    this->gameLineupId=gameLineupId;
    this->date=date;
    this->gameId=gameId;
    this->playerId=playerId;
    this->clubId=clubId;
    this->playerName=playerName;
    this->type=type;
    this->position=position;
    this->number=number;
}
int gameLineup::getClubId(){
    return clubId;
}
string gameLineup::getPlayerName(){
    return playerName;
}
int gameLineup::getGameId(){
    return gameId;
}

string gameLineup::getPosition(){
    return position;
}
string gameLineup::getType(){
    return type;
}
Date gameLineup::getDate(){
    return date;
}
int gameLineup::getPlayerId(){
    return playerId;
}
string gameLineup::toString(){
    return to_string(number)+" "+playerName+" "+position;
}
int gameLineup::getNumber(){
    return number;
}