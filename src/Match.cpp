#include "../include/Match.h"
#include <iostream>
#include <algorithm>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

double snd(double z) {
	double pi = 3.14159265;

	double sum = z;
	double fact = 1;
	for(int n=1; n<10; ++n) {
		double coef = (2*n+1);
		fact *= coef;
		sum += (pow(z,coef) / fact);
	}
	return 1/2. + sum * std::exp(-1*z*z/2) / sqrt(2*pi);
}

bool beat(const Player &x1, double e2, double v2) {
	double e = x1.getAvgRating() - e2;
	double v = sqrt(x1.getVariance() + v2);

	double x = (-1 * e) / v;
	double z = (x - e) / v;

	return 1 - snd(z);
}

double sumUntil(const std::vector<double>& goal_p, int last) {
	double res = 0;

	for(int i=0; i<last; ++i) {
		res+=goal_p[i];
	}

	return res;
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

	std::cout << teamA.getName() << " win: " << home_p << "   "
	<< teamB.getName() << " win: " << away_p << "   draw: "
	<< draw_p << std::endl << std::endl;
	std::cout << home_p + away_p + draw_p << std::endl;
}

void Match::calcResult_p() {
	int n = MIN(teamA.getPlayerCount(), teamA.getPlayerCount());

	std::vector<double> aGoal_p = teamA.getGoal_p();
	std::vector<double> bGoal_p = teamB.getGoal_p();

	result_p.resize(n);
	for(int i=0; i<n; ++i) result_p[i].resize(n);

	// double sum = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			result_p[i][j] = aGoal_p[i] * bGoal_p[j];
			// sum += result_p[i][j];
		}
	}
	// std::cout << sum << std::endl;
}

void Match::searchMostProbableResults() {
	int n = MIN(teamA.getPlayerCount(), teamA.getPlayerCount());
		// double max = 0;
	// int indexI, indexJ;
	// for(int i=0; i<n; ++i) {
		// for(int j=0; j<n; ++j) {
			// if(result_p[i][j] > max) {
				// max = result_p[i][j];
				// indexI = i;
				// indexJ = j;
			// }
			// std::cout << result_p[i][j] << " ";
		// }
		// std::cout << std::endl;
	// }
	// std::cout << max << " " << indexI << " " << indexJ << std::endl;
	struct Result {
		Result(double _p, int _h, int _a): p(_p), h(_h), a(_a) {}
		double p;
		int h,a;
	};

	std::vector<Result> results;
	// std::cout << "Most probable results: " << std::endl;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(result_p[i][j] > 0.05) {
				results.push_back(Result(result_p[i][j],i,j));
			}
		}
	}

	std::sort(results.begin(), results.end(), [](const Result& a, const Result& b){
		return a.p > b.p;
	});

	// for(int i=0; i<results.size() && i<5; ++i) {
		// std::cout << results[i].p << " " << results[i].h << " " << results[i].a << std::endl;
	// }
	// std::cout << std::endl << std::endl;
}
