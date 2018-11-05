#include "Team.h"
#include <iostream>

void Team::print() {
    std::cout << name << std::endl;
    for(Player player: players) {
        player.print();
    }
}
