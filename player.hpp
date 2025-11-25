#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "date.hpp"
#include <iostream>
using namespace std;
class Player{
    private:
        int playerId;
        int currentClubId;
        string firstName;
        string lastName;
        string name;
        int lastSeason;
        string countryOfBirth;
        Date dateOfBirth;
        string position;
        string subPosition;
        string currentClubName;
        float marketValue;
        float higuestMarketValue;
    public:
        Player(int playerId, int currentClubId, string firstName, string lastName, string name, int lastSeason, 
			string countryOfBirth, Date dateOfBirth, string position, string subPosition, string currentClubName, 
			float marketValue, float higuestMarketValue);
        int getCurrentClubId();
		string getName();
        float getMarketValue();
		int getLastSeason();
        string toString();
        int getPlayerId();
        string getPosition();
        string getSubPosition();
        int getAge();
};
#endif
