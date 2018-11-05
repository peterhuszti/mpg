#include "Player.h"
#include <iostream>

void Player::print() {
    std::cout << name << " goals: " << goals << " matchesPlayed: " << matchesPlayed << std::endl;
}
