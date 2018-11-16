#ifndef TEAM_H
#define TEAM_H

#include "Player.h"

class Team
{
    public:
        Team(std::string _name): name(_name) {
			positionRating.resize(4);
			positionVariance.resize(4);
		}

		std::string getName() const { return name; }
		int getPlayerCount() { return players.size(); }
		std::vector<double> getGoal_p() { return goal_p; }
		void setLineup(const std::vector<int> &_lineup) { lineup = _lineup; }
        void addPlayer(std::string _name, int _goals, int _matchesPlayed, int _starter, int _position, double _avgRating, double _variance);

        void calcGoal_p();
		void calcPlay_p();
		void calcPosAvg();

        void print();

    private:
        std::vector<Player> sortPlayers();        
		std::vector<double> goal_p;

        std::string name;
        std::vector<Player> players;
		std::vector<int> starter;
		
		std::vector<int> lineup;
		std::vector<double> positionRating;
		std::vector<double> positionVariance;
};

#endif // TEAM_H
