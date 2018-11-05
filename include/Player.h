#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <map>
#include <string>

class Player
{
    public:
        Player(std::string _name, int _goals, int _matchesPlayed):
            name(_name),
            goals(_goals),
            matchesPlayed(_matchesPlayed) {}

    private:
        std::string name;
        int goals;
        int matchesPlayed;
        double avgGoals;
        double goal_p;
        double play_p;
        std::vector<double> ratings;
        double avgRating;
        double tacticalSub_p;
        int position;
        double virtualGoal_p;
        std::map<double, double> ratingDistr_p;
};

#endif // PLAYER_H
