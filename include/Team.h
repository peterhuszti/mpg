#ifndef TEAM_H
#define TEAM_H

#include "Player.h"

class Team
{
    public:
        Team(std::string _name): name(_name) {}

		std::string getName() { return name; }
		int getPlayerCount() { return players.size(); }
		std::vector<double> getGoal_p() { return goal_p; }
        void addPlayer(std::string _name, int _goals, int _matchesPlayed);

        void calcGoal_p();

        void print();

    private:
        std::vector<Player> sortPlayers();        
		std::vector<double> goal_p;

        std::string name;
        std::vector<Player> players;
        std::map<int, double> goalDistr_p;
};

#endif // TEAM_H
