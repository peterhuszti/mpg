#include "../include/Player.h"
#include <iostream>

double Player::M = 11.;

void Player::print() {
    std::cout << name
              << "\n   goals: " << goals
              << "\n   matchesPlayed: " << matchesPlayed
              << "\n   avgGoals: " << avgGoals
              << "\n   playing probability: " << play_p
              << "\n   goal probability: " << goal_p
              << std::endl;
}
