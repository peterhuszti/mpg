#include <iostream>
#include <Team.h>
#include <utils/parser.h>

int main()
{
    Team ppa("PPA");
    parseTeam(ppa);
//    ppa.print();

double asd = 0;
std::vector<double> prob = ppa.calcGoal_p();
    for(int i=0; i<18; ++i)  {
        asd += prob[i];
        std::cout << i << " different player scores: " << prob[i] <<  " " << std::endl;
    }
    std::cout << "sum: " << asd;
    return 0;
}
