#ifndef GAMELINEUP_HPP
#define GAMELINEUP_HPP
#include <iostream>
#include "date.hpp"
using namespace std;
class gameLineup{
    private:
        string gameLineupId;
        Date date;
        int gameId;
        int playerId;
        int clubId;
        string playerName;
        string type;
        string position;
        int number;
        bool isCaptain;
    public:
        gameLineup(string gameLineupsId, Date date, int gameId, int playerId, int clubId, 
            string playerName, string type, string position, int number);
        gameLineup();
        int getClubId();
        string getPlayerName();
        int getGameId();
        string getType();
        string getPosition();
        Date getDate();
        int getPlayerId();
        string toString();
        int getNumber();
};
#endif