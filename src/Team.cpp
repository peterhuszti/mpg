#include "../include/Team.h"
#include <iostream>
#include <algorithm>
#include <math.h>

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
	double v = sqrt(x1.getVariance() + v2)
	
	double x = (-1 * e) / v;
	double z = (x - e) / v;
	
	return 1 - snd(z);
}

void Team::addPlayer(std::string _name, int _goals, int _matchesPlayed, int _starter, int _position, double _avgRating, double _variance) {
    players.push_back(Player(_name, _goals, _matchesPlayed, _starter, _position, _avgRating, _variance));
}

std::vector<Player> Team::sortPlayers() {
    std::vector<Player> sortedPlayers = players;
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const Player& a, const Player& b){
                        return a.getGoal_p() > b.getGoal_p();
                     });
    return sortedPlayers;
}

void Team::calcPlay_p() {	
	std::vector<std::vector<std::vector<Player> > > grouppedPlayers(4);
	// [position][starter][Player]
	for(int i=0; i<grouppedPlayers.size(); ++i) {
		grouppedPlayers[i].resize(2);
	}
	
	std::for_each(players.begin(), players.end(), [&grouppedPlayers](const Player& p){
		int tmp = p.getStarter();
		if(tmp==0) {
			grouppedPlayers[p.getPosition()][tmp].push_back(p);
		} else {
			grouppedPlayers[p.getPosition()][1].push_back(p);
		}
	});
		
	for(int i=0; i<grouppedPlayers.size(); ++i) {
		std::sort(grouppedPlayers[i][1].begin(), grouppedPlayers[i][1].end(), [](const Player& a, const Player& b){
                        return a.getStarter() < b.getStarter();
                     });		
	}
	
	for(int i=0; i<grouppedPlayers.size(); ++i) { // for all positions
		std::vector<double> beforeStart(grouppedPlayers[i][0].size(), 1);
		for(int k=0; k<grouppedPlayers[i][0].size(); ++k) { // for all starter
			for(int m=0; m<k; ++m) { // for all starter before this starter
				beforeStart[k] *= grouppedPlayers[i][0][m].getPlay_p();
			}
			beforeStart[k] *= (1 - grouppedPlayers[i][0][k].getPlay_p());
		}
	
		for(int j=0; j<grouppedPlayers[i][1].size(); ++j) { // for all non-starters
			std::vector<double> beforeSub(grouppedPlayers[i][1].size(), 1);
			for(int k=0; k<j; ++k) { // for all subs before this sub
				beforeSub[k] *= (1 - grouppedPlayers[i][1][k].getPlay_p());
			}
			
			double sum = 0;
			for(int k=0; k<beforeStart.size(); ++k) {
				sum += beforeStart[k] * beforeSub[j];
			}
			
			grouppedPlayers[i][1][j].setPlay_p(grouppedPlayers[i][1][j].getPlay_p() * sum);
		}
	}
	players.clear();
	for(int i=0; i<grouppedPlayers.size(); ++i) {
		for(int j=0; j<grouppedPlayers[i].size(); ++j) {
			for(int k=0; k<grouppedPlayers[i][j].size(); ++k) {
				players.push_back(grouppedPlayers[i][j][k]);
			}
		}
	}
}

void Team::calcGoal_p() {
	calcPlay_p();
	
	for(int i=0; i<players.size(); ++i) {
		players[i].recalcGoal_p();
	}
	
    double res = 1;
    int n = players.size();
	std::vector<std::vector<double> > p;

    std::vector<Player> sortedPlayers = sortPlayers();
    p.resize(n);
    for(int i=0;i<n;++i) p[i].resize(n);

    p[0][1] = 1-sortedPlayers[0].getGoal_p();
    p[1][1] = sortedPlayers[0].getGoal_p();

    for(int i=1; i<n-1; ++i) {
        double prob_i = sortedPlayers[i].getGoal_p();
        p[0][i+1] = p[0][i] * (1-prob_i);
        p[i+1][i+1] = p[i][i] * prob_i;

        for(int j=1; j<i+1; ++j) {
            double prob_iplusone = sortedPlayers[i+1].getGoal_p();
            p[j][i+1] = p[j][i]*(1-prob_iplusone) + p[j-1][i]*prob_iplusone;
        }
    }

//    for(int i=0; i<n; ++i) {
//        for(int j=0; j<n; ++j) {
//            std::cout << p[i][j] << "     ";
//        }
//        std::cout << std::endl;
//    }

    for(int j=0; j<n; ++j) {
        goal_p.push_back(p[j][n-1]);
    }
	
	calcPosAvg();
}

void Team::calcPosAvg() {
	std::vector<std::vector<Player> > grouppedPlayers(4);
	// [position][Player]
	
	std::for_each(players.begin(), players.end(), [&grouppedPlayers](const Player& p){
		int tmp = p.getStarter();
		if(tmp==0) {
			grouppedPlayers[p.getPosition()].push_back(p);
		} 
	});
	
	for(int i=1; i<grouppedPlayers.size(); ++i) { // for all positions, except keepers
		double avg = 0;
		double var = 0;
		int n = grouppedPlayers[i].size();
		for(int j=0; j<n; ++j) {
			avg += grouppedPlayers[i][j].getAvgRating();
			var += grouppedPlayers[i][j].getVariance();
		}
		avg /= grouppedPlayers[i].size();
		var /= grouppedPlayers[i].size();
		
		if(i==1) {
			if(n==4) {
				avg += 0.5;
			} else if(n==5) {
				avg += 1;
			}
		}
		
		// std::cout << avg << "   " << var << std::endl;
		
		positionRating[i] = avg;
		positionVariance[i] = var;
	}
}

void Team::print() {
    std::cout << name << std::endl;
    for(Player player: players) {
        // player.print();
    }
	std::cout << "Formation: ";
	for(int i=0; i<lineup.size(); ++i) {
		std::cout << lineup[i] << " - ";
	}
	std::cout << std::endl;
}
