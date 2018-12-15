#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <map>
#include <string>

class Player
{
    public:
        static double M;

        Player(std::string _name, int _goals, int _matchesPlayed, int _starter, int _position, double _avgRating, double _variance):
            name(_name),
            goals(_goals),
            matchesPlayed(_matchesPlayed),
			starter(_starter),
			position(_position),
			avgRating(_avgRating),
			variance(_variance)	{

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

        std::string getName() { return name; }
        double getPlay_p() { return play_p; }
		double setPlay_p(double p) { play_p = p; }
        double getGoal_p() const { return goal_p; }
		int getPosition() const { return position; }
		int getStarter() const { return starter; }
		double getAvgRating() const { return avgRating; }
		double getVariance() const { return variance; }

		void recalcGoal_p() { goal_p = avgGoals * play_p; }

        void print();

    private:
        std::string name;
        int goals;
        int matchesPlayed;
		int starter; // 0 - starter, 1-6 - position in the bench
		int position; // 0 - G, 1 - D, 2 - M, 3 - F
        double avgGoals;
        double play_p;
        double goal_p;
		double avgRating;
		double variance;

		// not used yet
        std::vector<double> ratings;
        double tacticalSub_p;
        double virtualGoal_p;
};

#endif // PLAYER_H
