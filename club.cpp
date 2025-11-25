#include "club.hpp"
Club::Club(int clubId,string domesticCompetitionId,
        string clubName,int squadSize,float averageAge,string stadiumName){
    this->clubId=clubId;
	this->domesticCompetitionId=domesticCompetitionId;
	this->clubName=clubName;
	this->squadSize=squadSize;
	this->averageAge=averageAge;
	this->stadiumName=stadiumName;
	numberOfPlayers=0;
}

void Club::showBestPlayer(){
    bool bigger;
    for(int i=0;i<players.size();i++){
        bigger=true;
        for(int j=0;j<players.size();j++){
            if(players.at(i).getMarketValue()<players.at(j).getMarketValue()){
                bigger=false;
                break;
            }
        }
        if(bigger==true){
            cout<<"Best player: "<<players.at(i).getName()<<" Market Value"<<players.at(i).getMarketValue()<<"€"<<endl;
        }
    }

    
}
void Club::sortPlayers(){
	int election,election2;
    int minimum,maximum;
    int minimumAge, maximumAge;
    string position;
    cout<<"SORT PLAYERS"<<endl<<"-----------"<<endl;
    cout<<"1.Market Value"<<endl<<"2.Position"<<endl<<"3.Age"<<endl;
    cin>>election;
    switch(election){
        case 1:
            cout<<"Introduce the minimum market value: ";
            cin>>minimum;
            cout<<"Introduce the maximum market value: ";
            cin>>maximum;
            cout<<"Players with market Value between "<<minimum<<"$ and "<<maximum<<"$: "<<endl;
            for(int i=0;i<players.size();i++){
                if(minimum<players.at(i).getMarketValue()<maximum ){
                    cout<<players.at(i).getName()<<" Market Value: "<<players.at(i).getMarketValue()<<endl;
                }
            }
            break;
        case 2:
            cout<<"1.Attack"<<endl<<"2.Goalkeeper"<<endl<<"3.Defender"<<endl<<"4.Midfield"<<endl;
            cin>>election2;
            switch(election2){
                case 1:
                    position="Attack";
                    break;
                case 2:
                    position="Goalkeeper";
                    break;
                case 3:
                    position="Defender";
                    break;
                case 4:
                    position="Midfield";
                    break;
            }
            cout<<"Players with position: "<<position<<endl;
            for(int i=0;i<players.size();i++){
                if(players.at(i).getPosition()==position){
                    cout<<players.at(i).getName()<<endl;
                }
                else if(players.at(i).getSubPosition()==position){
                    cout<<players.at(i).getName()<<endl;
                }
            }
            break;
        case 3:
            cout<<"Introduce the minimum age: ";
            cin>>minimumAge;
            cout<<"Introduce the maximum age: ";
            cin>>maximumAge;
            for(int i=0;i<players.size();i++){
                if(minimumAge<players.at(i).getAge() && players.at(i).getAge()<maximumAge){
                    cout<<players.at(i).getName()<<" Age: "<<players.at(i).getAge()<<endl;
                }
            }
            break;

    }
}
string Club::getCoachName(){
	return coachName;
}
float Club::getAverageAge(){
	return averageAge;
}
string Club::getClubName(){
	return clubName;
}
vector<Player> Club::getPlayers(){
	return players;
}
void Club::setLineupAndPlayers(vector<gameLineup> lineups,vector<Player> players2){
    vector <gameLineup> lineupStarting;
    vector <gameLineup> lineupSubstitute;
    int month=0;
    int gameId;
    for(int i=0;i<lineups.size();i++){
        if(lineups.at(i).getClubId()==clubId && lineups.at(i).getDate().year==2023 && 
                lineups.at(i).getDate().month>month){
                    month=lineups.at(i).getDate().month;
                    gameId=lineups.at(i).getGameId();
        }
    }
    for(int i=0;i<lineups.size();i++){
        if(lineups.at(i).getClubId()==clubId && gameId==lineups.at(i).getGameId()){
            for(int j=0;j<players2.size();j++){
                if(players2.at(j).getPlayerId()==lineups.at(i).getPlayerId()){
                    players.push_back(players2.at(j));
                }
            }
            lineup.push_back(lineups.at(i));
        }
    }
}
int Club::getClubId(){
    return clubId;
}
void Club::showLineup(){
    cout<<"Lineup: "<<endl;
    for(int i=0;i<lineup.size();i++){
        if(lineup.at(i).getType()=="starting_lineup"){
            cout<<lineup.at(i).getNumber()<<". "<<lineup.at(i).getPlayerName()<<" "<<lineup.at(i).getPosition()<<endl;
        }
    }
}
string Club::getDomesticCompetitionId(){
    return domesticCompetitionId;
}
int Club::getSquadSize(){
    return squadSize;
}