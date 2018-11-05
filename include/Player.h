#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <map>
#include <string>

class Player
{
    public:
        static double M;

        Player(std::string _name, int _goals, int _matchesPlayed):
            name(_name),
            goals(_goals),
            matchesPlayed(_matchesPlayed) {

            if(matchesPlayed==0) {
                avgGoals = 0;
            } else {
                avgGoals = (double)goals / matchesPlayed;
            }
            play_p = matchesPlayed / M;
            if(play_p == 0) {
                play_p = 0.001;
            }
            goal_p = avgGoals * play_p;
            if(goal_p == 0) {
                goal_p = 0.001;
            }
        }

        void updateData();

        std::string getName() { return name; }
        double getPlay_p() { return play_p; }
        double getGoal_p() const { return goal_p; }

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
