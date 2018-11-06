#ifndef MATCH_H
#define MATCH_H

#include "Team.h"

class Match
{
    public:
        Match(Team a, Team b): teamA(a), teamB(b) {
			home_p = away_p = draw_p = 0;
			calcWin_p();
			calcResult_p();
			searchMostProbableResults();
		}
		
		void calcWin_p();
		void calcResult_p();
		void searchMostProbableResults();
		
		double getHome_p() {return home_p; }
		double getAway_p() {return away_p; }
		double getDraw_p() {return draw_p; }
		
        void print();

    private:
        Team teamA, teamB;
		
		double home_p, away_p, draw_p;
		std::vector<std::vector<double> > result_p;
};

#endif // MATCH_H
