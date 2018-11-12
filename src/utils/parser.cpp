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
	int starter;
	int position;

    while(getline(input, line)) {
        std::stringstream ss(line);

        std::string tmp;
        int i = 0;

        while(getline(ss, tmp, '\t')) {
			if(i==0) {
				starter = atoi(tmp.c_str());
			}
            else if(i==1) {
               // std::cout << tmp << " ";
                name = tmp;
            }
			else if(i==2) {
				if(tmp == "G") position = 0;
				else if(tmp == "D") position = 1;
				else if(tmp == "M") position = 2;
				else if(tmp == "F") position = 3;
			}
            else if(i==4) {
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
            else if(i==6) {
//                std::cout << tmp << std::endl;
                goals = atoi(tmp.c_str());
            }

            i++;
        }
        team.addPlayer(name, goals, matchesPlayed, starter, position);
    }


    input.close();
}
