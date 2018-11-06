#include <iostream>
#include "include/Team.h"
#include "include/utils/parser.h"

int main()
{
	std::vector<std::string> teamNames = {"ppa", "ala"};
	std::vector<Team> teams;
	
	for(auto t: teamNames) {
		Team temp(t);
		teams.push_back(std::move(temp));
	}
	
	for(int i=0; i<teams.size(); ++i) {
		parseTeam(teams[i]);
		// t.print();
	}
	
	for(auto t: teams) {
		double sum = 0;
		std::vector<double> prob = t.calcGoal_p();
		for(int i=0; i<t.getPlayerCount(); ++i)  {
			sum += prob[i];
			// std::cout << i << " different player scores: " << prob[i] <<  " " << std::endl;
		}
		std::cout << "sum: " << sum << std::endl;
	}
	
    return 0;
}
