#include "../../include/Team.h"
#include "../../include/Player.h"
#include "../../include/utils/parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

void parseTeam(Team &team) {
	std::string prefix = "input/";
	std::string file = prefix + team.getName() + ".txt";
	
    std::ifstream input(file);

    std::string line;

    std::string name;
    int goals;
    int matchesPlayed;

    while(getline(input, line)) {
        std::stringstream ss(line);

        std::string tmp;
        int i = 0;

        while(getline(ss, tmp, '\t')) {
            if(i==0) {
//                std::cout << tmp << " ";
                name = tmp;
            }
            else if(i==3) {
//                std::cout << tmp << " ";
                int found = tmp.find("/");
                if (found!=std::string::npos) {
                    tmp.erase(tmp.begin(), tmp.begin()+found+1);
                }
//                std::cout << tmp << " ";
                found = tmp.find("{");
                if (found!=std::string::npos) {
                    tmp.erase(tmp.begin()+found, tmp.end());
                    matchesPlayed = atoi(tmp.c_str());
//                    std::cout << atoi(tmp.c_str()) << " ";
                } else {
                    found = tmp.find("}");
                    if (found!=std::string::npos) {
                        matchesPlayed = 0;
                    } else {
                        matchesPlayed = atoi(tmp.c_str());
                    }
                }
//                std::cout << tmp << " ";
            }
            else if(i==5) {
//                std::cout << tmp << std::endl;
                goals = atoi(tmp.c_str());
            }

            i++;
        }
        team.addPlayer(name, goals, matchesPlayed);
    }


    input.close();
}
