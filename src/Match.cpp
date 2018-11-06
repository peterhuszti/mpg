#include "../include/Match.h"
#include <iostream>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

double sumUntil(const std::vector<double>& goal_p, int last) {
	double res = 0;
	
	for(int i=0; i<last; ++i) {
		res+=goal_p[i];
	}
}

void Match::calcWin_p() {
	int n = MIN(teamA.getPlayerCount(), teamA.getPlayerCount());
	
	std::vector<double> home(n);
	std::vector<double> away(n);
	std::vector<double> draw(n);
	
	std::vector<double> aGoal_p = teamA.getGoal_p();
	std::vector<double> bGoal_p = teamB.getGoal_p();
	
	for(int i=0; i<n; ++i) {
		home[i] = aGoal_p[i] * sumUntil(bGoal_p, i);
		away[i] = bGoal_p[i] * sumUntil(aGoal_p, i);
		draw[i] = aGoal_p[i] * bGoal_p[i];
	}
	
	home_p = sumUntil(home, n);
	away_p = sumUntil(away, n);
	draw_p = sumUntil(draw, n);
	
	std::cout << home_p << " " << away_p << " " << draw_p << std::endl;
}