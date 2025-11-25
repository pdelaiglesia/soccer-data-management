#include "player.hpp"
Player::Player(int playerId, int currentClubId, string firstName, string lastName, string name, int lastSeason, 
	string countryOfBirth, Date dateOfBirth, string position, string subPosition, string currentClubName, 
	float marketValue, float higuestMarketValue){
	this->playerId=playerId;
	this->currentClubId=currentClubId;
	this->firstName=firstName;
	this->lastName=lastName;
	this->name=name;
	this->lastSeason=lastSeason;
	this->countryOfBirth=countryOfBirth;
	this->dateOfBirth=dateOfBirth;
	this->position=position;
	this->subPosition=subPosition;
	this->currentClubName=currentClubName;
	this->marketValue=marketValue;
	this->higuestMarketValue=higuestMarketValue;
}
int Player::getCurrentClubId(){
	return currentClubId;
}
string Player::getName(){
	return name;
}
float Player::getMarketValue(){
	return marketValue;
}
int Player::getLastSeason(){
	return lastSeason;
}
string Player::toString(){
    return "hola";
}
int Player::getPlayerId(){
	return playerId;
}
string Player::getPosition(){
	return position;
}
string Player::getSubPosition(){
	return subPosition;
}
int Player::getAge(){
	return 2024-dateOfBirth.year;
}