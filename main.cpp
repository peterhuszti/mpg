#include <iostream>
#include "include/Team.h"
#include "include/Match.h"
#include "include/utils/parser.h"

Team findTeam(const std::vector<Team>& teams, std::string name) {
	for(auto t: teams) {
		if(t.getName() == name) {
			return t;
		}
	}
}

int main()
{
	// std::vector<std::string> teamNames = {"ppa", "ala", "zhu", "lit", "pcl", "bkv"};
	std::vector<std::string> teamNames = {"ppa"};
	std::vector<Team> teams;
	
	for(auto t: teamNames) {
		Team temp(t);
		teams.push_back(std::move(temp));
	}
	
	for(int i=0; i<teams.size(); ++i) {
		parseTeam(teams[i]);
		teams[i].print();
	}
	
	for(int i=0; i<teams.size(); ++i) {
		// double sum = 0;
		teams[i].calcGoal_p();
		std::vector<double> goal_p = teams[i].getGoal_p();
		for(int i=0; i<teams[i].getPlayerCount(); ++i)  {
			// sum += goal_p[i];
			// std::cout << i << " different player scores: " << goal_p[i] <<  " " << std::endl;
		}
		// std::cout << "sum: " << sum << std::endl;
	}
	// Match(findTeam(teams,"ppa"), findTeam(teams,"ala"));
	// Match(findTeam(teams,"zhu"), findTeam(teams,"lit"));
	// Match(findTeam(teams,"pcl"), findTeam(teams,"bkv"));
	
    return 0;
}
