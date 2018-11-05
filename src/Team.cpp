#include "Team.h"
#include <iostream>

void Team::addPlayer(std::string _name, int _goals, int _matchesPlayed) {
    players.push_back(Player(_name, _goals, _matchesPlayed));
}

void Team::print() {
    std::cout << name << std::endl;
    for(Player player: players) {
        player.print();
    }
}
