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

void simulateSeason(const std::vector<Team> &teams) {
	int n = teams.size();
	
	std::vector<double> points(n,0);
	
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			Match match(teams[i], teams[j]);
			points[i] += 6 * match.getHome_p();
			points[i] += 2 * match.getDraw_p();
			
			points[j] += 6 * match.getAway_p();
			points[j] += 2 * match.getDraw_p();
		}
	}
	
	for(int i=0; i<n; ++i) { 
		std::cout << teams[i].getName() << ": " << points[i] << std::endl;
	}
}

int main()
{
	// std::vector<std::string> teamNames = {"ppa", "lit", "pcl", "bkv", "nle", "ala", "ong", "kot"};
	std::vector<std::string> teamNames = {"ppa"};
	std::vector<Team> teams;
	
	for(auto t: teamNames) {
		Team temp(t);
		teams.push_back(std::move(temp));
	}
	
	for(int i=0; i<teams.size(); ++i) {
		parseTeam(teams[i]);
		// teams[i].print();
	}
	
	for(int i=0; i<teams.size(); ++i) {
		// std::cout << teams[i].getName() << std::endl;
		// double sum = 0;
		teams[i].calcGoal_p();
		teams[i].print();
		std::vector<double> goal_p = teams[i].getGoal_p();
		for(int j=0; j<teams[i].getPlayerCount(); ++j)  {
			// sum += goal_p[i];
			// std::cout << j << " different player scores: " << goal_p[j] <<  " " << std::endl;
		}
		// std::cout << "sum: " << sum << std::endl;
	}
	// Match(findTeam(teams,"ong"), findTeam(teams,"nle"));
	// Match(findTeam(teams,"ala"), findTeam(teams,"lit"));
	// Match(findTeam(teams,"pcl"), findTeam(teams,"ppa"));
	// Match(findTeam(teams,"kot"), findTeam(teams,"bkv"));
	
	// simulateSeason(teams);
	
    return 0;
}
