#include <iostream>
#include <Team.h>
#include <utils/parser.h>

int main()
{
    Team ppa("PPA");
    parseTeam(ppa);
    ppa.print();
    return 0;
}
