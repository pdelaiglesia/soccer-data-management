#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "club.hpp"
#include "player.hpp"
#include "gameLineup.hpp"
using namespace std;
void cargaDatos(vector<Club> &clubs, vector<Player> &players, vector<gameLineup> &lineup);
Date convertString(string word);
void clubsMenu(vector<Club> &clubs);
void clubByName(vector<Club> &clubs);
void generalClubsMenu(vector<Club> clubs);
void showClubsByLeagues(vector<Club> clubs);
void sortClubs(vector<Club> clubs);
int main(){
    vector<gameLineup> lineups;
    vector<Player> players;
	vector<Club> clubs;
    cargaDatos(clubs,players,lineups);
    for(int i=0;i<clubs.size();i++){
        if(clubs.at(i).getClubId()==418){
            clubs.at(i).setLineupAndPlayers(lineups,players);
        }
    }
    clubsMenu(clubs);
    cout<<"Thanks"<<endl;
}
void sortClubs(vector<Club> clubs){
    int election, min, max;
    cout<<"Sort Clubs"<<endl;
    cout<<"----------"<<endl;
    cout<<"1. Average age"<<endl;
    cout<<"2. Squad Size"<<endl;
    cout<<"Enter a number 1-2: ";
    cin>>election;
    while(election<1||election>2){
        cout<<"Error, enter a number 1 or 2: ";
        cin>>election;
    }
    cout<<"Enter the minimum: ";
    cin>>min;
    cout<<"Enter the maximum: ";
    cin>>max;
    switch(election){
        case 1:
            cout<<"Clubs with average age bewteen "<<min<<" and "<<max<<": "<<endl;
            for(int i=0;i<clubs.size();i++){
                if(min<clubs.at(i).getAverageAge() && clubs.at(i).getAverageAge()<max){
                    cout<<clubs.at(i).getClubName()<<" Average Age:"<<clubs.at(i).getAverageAge()<<endl;
                }
            }
            break;
        case 2:
            cout<<"Clubs with squad size bewteen "<<min<<" and "<<max<<": "<<endl;
            for(int i=0;i<clubs.size();i++){
                if(min<clubs.at(i).getSquadSize() && clubs.at(i).getSquadSize()<max){
                    cout<<clubs.at(i).getClubName()<<" Squad Size: "<<clubs.at(i).getSquadSize()<<endl;
                }
            }
            break;
    }
}
void showClubsByLeagues(vector<Club> clubs){
    int election, position;
    vector<string> leagues;
    bool already=false;
    for(int i=0;i<clubs.size();i++){
        for(int j=0;j<leagues.size();j++){
            if(clubs.at(i).getDomesticCompetitionId()==leagues.at(j)){
                already=true;
            }

        }
        if(already==false){
            leagues.push_back(clubs.at(i).getDomesticCompetitionId());
        }
        already=false;
    }
    cout<<"Leagues:"<<endl;
    for(int i=0;i<leagues.size();i++){
        cout<<i+1<<". "<<leagues.at(i)<<endl;
    }
    cout<<"Enter a league: ";
    cin>>election;
    position=election-1;
    cout<<"Clubs in league "<<leagues.at(position)<<": "<<endl;
    for(int i=0;i<clubs.size();i++){
        if(clubs.at(i).getDomesticCompetitionId()==leagues.at(position)){
            cout<<clubs.at(i).getClubName()<<endl;
        }
    }
}
void generalClubsMenu(vector<Club> clubs){
    int election;
    bool exit=false;
    while(exit==false){
        cout<<"General Clubs Menu"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Show clubs in Leagues"<<endl;
        cout<<"2.Sort Clubs"<<endl;
        cout<<"3.Return to Clubs Menu"<<endl;
        cout<<"Enter a number between 0-2:";
        cin>>election;
        while(election<0||election>2){
            cout<<"Error, enter a number between 0-2: ";
            cin>>election;
        }
        switch(election){
            case 0:
                exit=true;
                break;
            case 1:
                showClubsByLeagues(clubs);
                break;
            case 2:
                sortClubs(clubs);
                break;
        }
    }
}
void clubByName(vector<Club> &clubs){
    int election;
    vector<Club> results;
    string search1, search;
    bool equal, exit=false;
    cout<<"Enter word to search."<<endl<<"(It will be searched according to the beginning of the word, if you want to search for Real Madrid enter Real for example or Real Madrid)"<<endl;
    cin>>search;
    getline(cin,search1);
    search=search+search1;
    for(int i=0;i<clubs.size();i++){
        equal=true;
        for(int j=0;j<search.size();j++){
            if(search[j]==clubs.at(i).getClubName()[j]){
            }
            else{
                equal=false;
                break;
            }
        }
        if(equal==true){
            results.push_back(clubs.at(i));
        }
    }
    if(results.size()>0){
        for(int i=0;i<results.size();i++){
            cout<<i+1<<". "<<results.at(i).getClubName()<<endl;
        }
        cout<<"Enter number of the club: ";
        cin>>election;
        while(election<0||election>results.size()){
            cout<<"Error, enter a number between 0 and "<<results.size()<<endl;
            cin>>election;
        }
        int clubPosition=election-1;
        while(exit==false){
            cout<<"MENU CLUB:"<<endl<<endl;
            cout<<"1.Show Best Player"<<endl;
            cout<<"2.Sort Players"<<endl;
            cout<<"3.Show Lineup"<<endl;
            cout<<"4.Show Average Age"<<endl;
            cout<<"0.Return to Clubs Menu"<<endl;
            cin>>election;
            while(election<0||election>5){
                cout<<"Error,enter a number between 0-5: ";
                cin>>election;
            }
            switch(election){
                case 0:
                    exit=true;
                    break;
                case 1:
                    results.at(clubPosition).showBestPlayer();
                    break;
                case 2:
                    results.at(clubPosition).sortPlayers();
                    break;
                case 3:
                    results.at(clubPosition).showLineup();
                    break;
                case 4:
                    cout<<"Average Age: "<<results.at(clubPosition).getAverageAge()<<endl;
                    break;
            }
        }
    }
    else{
        cout<<"None results"<<endl;
    }
}
void clubsMenu(vector<Club> &clubs){
    bool exit =false;
    int election;
    while(exit==false){
        cout<<"MENU CLUBS: "<<endl<<endl;
        cout<<"1. Introduce club: "<<endl;
        cout<<"2. Show general Information"<<endl;
        cout<<"0. Return to general menu"<<endl;
        cout<<"Enter election:";
        cin>>election;
        while(election<0||election>2){
            cout<<"Error enter a number between 1-2: ";
            cin>>election;
        }
        switch(election){
            case 0:
                exit=true;
                break;
            case 1:
                clubByName(clubs);
                break;
            case 2:
                generalClubsMenu(clubs);
                break;
        }
    }
}
Date convertString(string word2){
    Date date;
    stringstream strstr(word2);
		string word="  ";
		int z=0;
	while(getline(strstr,word,'-')){
        if(z==0){
            date.year=stoi(word);
        }
        else if(z==1){
            date.month=stoi(word);
        }
        else{
            date.day=stoi(word);
        }
        z++;
    }
    return date;
}
void cargaDatos(vector<Club> &clubs, vector<Player> &players, vector<gameLineup> &lineups){
    ifstream infile("clubs.csv");
    string line = "   "; 
    vector<string> datos_csv;
    while (getline(infile, line))
    {
        stringstream strstr(line);
        string word="  ";
        while(getline(strstr,word,','))
        {
            datos_csv.push_back(word);
        }
    }
    string averageAge;
    cout<<"Loading clubs"<<endl;
    for(int i=1; i<427;i++)
    {
    	averageAge=datos_csv.at(23+17*(i-1));
    	if(averageAge==""){
    		averageAge="0";
		}
    	Club club(stoi(datos_csv.at(17*i)),datos_csv.at(20+17*(i-1)),datos_csv.at(19+17*(i-1)),stoi(datos_csv.at(22+17*(i-1))),stoi(averageAge),datos_csv.at(27+17*(i-1)));
    	clubs.push_back(club);
    }
    infile.close();
    ifstream infile2("players.csv");
    line="  ";
    datos_csv.clear();
    while(getline(infile2,line)){
    	stringstream strstr(line);
    	string word="  ";
    	while(getline(strstr,word,',')){
    		datos_csv.push_back(word);
		}
	}
    cout<<"Loading players"<<endl;
	for(int i=1;i<30513;i++){
		string marketValue, higuestMarketValue;
		marketValue=datos_csv.at(45+(24*(i-1)));
		higuestMarketValue=datos_csv.at(46+(24*(i-1)));
		if(marketValue==""){
			marketValue="0";
		}
		if(higuestMarketValue==""){
			higuestMarketValue="0";
		}
		Player player(stoi(datos_csv.at(24*i)),stoi(datos_csv.at(29+(24*(i-1)))),
            datos_csv.at(25+(24*(i-1))),datos_csv.at(26+(24*(i-1))),datos_csv.at(27+(24*(i-1))),
            stoi(datos_csv.at(28+(24*(i-1)))),datos_csv.at(31+(24*(i-1))),convertString(datos_csv.at(34+(24*(i-1)))),
            datos_csv.at(36+(24*(i-1))),datos_csv.at(35+(24*(i-1))),datos_csv.at(44+(24*(i-1))),
            stoi(marketValue),stoi(higuestMarketValue));
		players.push_back(player);	
	}
    infile2.close();
    ifstream infile3("game_lineups.csv");
    line="  ";
    datos_csv.clear();
    while(getline(infile3,line)){
    	stringstream strstr(line);
    	string word="  ";
    	while(getline(strstr,word,',')){
    		datos_csv.push_back(word);
		}
	}
    cout<<"Loading Lineups"<<endl;
    string number;
    for(int i=1;i<2145223;i++){
        number=datos_csv.at(18+10*(i-1));
        if(number=="-"){
            number="0";
        }
        gameLineup lineup(datos_csv.at(10*i),convertString(datos_csv.at(11+10*(i-1))),stoi(datos_csv.at(12+10*(i-1))),
            stoi(datos_csv.at(13+10*(i-1))),stoi(datos_csv.at(14+10*(i-1))),
            datos_csv.at(15+10*(i-1)),datos_csv.at(16+10*(i-1)),datos_csv.at(17+10*(i-1)),
            stoi(number));
        lineups.push_back(lineup);
    }
    infile3.close();
}