#ifndef TEAM_H
#define TEAM_H

#include <Player.h>

class Team
{
    public:
        Team(std::string _name): name(_name) {}

        void addPlayer(std::string _name, int _goals, int _matchesPlayed);

        void print();

    private:
        std::string name;
        std::vector<Player> players;
        std::map<int, double> goalDistr_p;
};

#endif // TEAM_H
