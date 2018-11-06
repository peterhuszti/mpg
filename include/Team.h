#ifndef TEAM_H
#define TEAM_H

#include "Player.h"

class Team
{
    public:
        Team(std::string _name): name(_name) {}

		std::string getName() { return name; }
		int getPlayerCount() { return players.size(); }
        void addPlayer(std::string _name, int _goals, int _matchesPlayed);

        std::vector<double> calcGoal_p();

        void print();

    private:
        std::vector<Player> sortPlayers();
        std::vector<std::vector<double> > p;

        std::string name;
        std::vector<Player> players;
        std::map<int, double> goalDistr_p;
};

#endif // TEAM_H
