#include "Team.h"
#include <iostream>
#include <algorithm>

void Team::addPlayer(std::string _name, int _goals, int _matchesPlayed) {
    players.push_back(Player(_name, _goals, _matchesPlayed));
}

std::vector<Player> Team::sortPlayers() {
    std::vector<Player> sortedPlayers = players;
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const Player& a, const Player& b){
                        return a.getGoal_p() > b.getGoal_p();
                     });
    return sortedPlayers;
}

std::vector<double> Team::calcGoal_p() {
    double res = 1;
    std::vector<double> res_v;
    int n = players.size();

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
        res_v.push_back(p[j][n-1]);
    }

    return res_v;
}

void Team::print() {
    std::cout << name << std::endl;
    for(Player player: players) {
        player.print();
    }
}
