#ifndef CLUB_HPP
#define CLUB_HPP
#include <iostream>
#include <vector>
#include "player.hpp"
#include "gameLineup.hpp"
using namespace std;
class Club{
    private:
        int clubId;
        string domesticCompetitionId;
        string clubName;
        int squadSize;
        float averageAge;
        string stadiumName;
        string coachName;
        vector<Player> players;
        int numberOfPlayers;
        vector<gameLineup> lineup;
    public:
        Club(int clubId,string domesticCompetitionId,
            string clubName,int squadSize,float averageAge,string stadiumName);
        void showBestPlayer();
        void sortPlayers();
        void setLineupAndPlayers(vector<gameLineup> lineups,vector<Player> players2);
        string getCoachName();
        float getAverageAge();
        string getClubName();
		vector<Player> getPlayers();
        int getClubId();
        void showLineup();
        string getDomesticCompetitionId();
        int getSquadSize();
};
#endif