#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <map>
#include <string>

#define M 11.

class Player
{
    public:
        Player(std::string _name, int _goals, int _matchesPlayed):
            name(_name),
            goals(_goals),
            matchesPlayed(_matchesPlayed) {

            avgGoals = (double)goals / matchesPlayed;
            play_p = matchesPlayed / M;
            goal_p = avgGoals * play_p;
            }

        void updateData();

        void print();

    private:
        std::string name;
        int goals;
        int matchesPlayed;
        double avgGoals;
        double play_p;
        double goal_p;
        std::vector<double> ratings;
        double avgRating;
        double tacticalSub_p;
        int position;
        double virtualGoal_p;
        std::map<double, double> ratingDistr_p;
};

#endif // PLAYER_H
