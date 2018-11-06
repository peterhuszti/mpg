#include <iostream>
#include "include/Team.h"
#include "include/utils/parser.h"

int main()
{
    Team ppa("PPA");
    parseTeam(ppa);
//    ppa.print();
	Team ala("ALA");
	parseTeam(ala);
	ala.print();

	double sum = 0;
	std::vector<double> prob = ppa.calcGoal_p();
    for(int i=0; i<18; ++i)  {
        sum += prob[i];
        std::cout << i << " different player scores: " << prob[i] <<  " " << std::endl;
    }
    std::cout << "sum: " << sum;
	
	sum = 0;
	prob = ala.calcGoal_p();
    for(int i=0; i<18; ++i)  {
        sum += prob[i];
        std::cout << i << " different player scores: " << prob[i] <<  " " << std::endl;
    }
    std::cout << "sum: " << sum;
	
    return 0;
}
