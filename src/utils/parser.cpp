#include <Team.h>
#include <Player.h>
#include <utils/parser.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

#define PPA "input/ppa.txt"

void parseTeam(Team &ppa) {
    std::ifstream input(PPA);

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
                name = tmp;
            }
            else if(i==3) {
                int found = tmp.find("/");
                if (found!=std::string::npos) {
                    tmp.erase(tmp.begin(), tmp.begin()+found+1);
                }
                found = tmp.find("{");
                if (found!=std::string::npos) {
                    tmp.erase(tmp.begin()+found, tmp.end());
                }
                matchesPlayed = atoi(tmp.c_str());
            }
            else if(i==5) {
                goals = atoi(tmp.c_str());
            }

            i++;
        }
        ppa.addPlayer(name, goals, matchesPlayed);
    }


    input.close();
}
