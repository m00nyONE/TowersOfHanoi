//
//

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <vector>

bool showsteps = true; //CHANGE THIS TO SPEED UP THE PROCESS OR TO SHOW EVERY STEP!
int Steps;

std::vector<std::vector<int>> _tower(3);

void printTowers();
void setTower(int hight, int from=1, int to=3, int with=2);

int main()
{
        int disks;

        std::cout << "How many disks should the tower have? " << std::endl;
        std::cin >> disks;

        for (int i = 0; i<disks; i++)
        {
                _tower[0].push_back(disks - i);
        }

        printTowers();
        std::cout << "##############################################" << std::endl;

        setTower(_tower[0].size());

        std::cout << "##############################################" << std::endl;
        printTowers();
        std::cout << "Schritte: " << Steps << std::endl;


        system("pause");
        return 0;
}


void printTowers()
{
        system("cls");

        int tmp = 0;

        for (int i = 0; i < _tower.size(); i++)
        {
                if (_tower[i].size() > tmp)
                {
                        tmp = _tower[i].size();
                }
        }
        for (int i = tmp; i >= 0; i--)
        {
                for (int j = 0; j < _tower.size(); j++)
                {
                        if ( i < _tower[j].size())
                                std::cout << "[" << _tower[j][i] << "]\t";
                        else
                                std::cout << "\t";
                }
                std::cout << std::endl;
        }
        std::cout << "tow1\ttow2\ttow3" << std::endl;
}

void setTower(int hight,int from,int to,int with)
{
        if ( hight > 0)
        {
                setTower((hight - 1), from, with, to);
                _tower[to - 1].push_back(_tower[from - 1].back()
                );
                _tower[from - 1].pop_back();

                Steps++;
                std::cout << "Step: " << Steps << " \n\n";

                if (showsteps)
                {
                        printTowers();
                        system("pause");
                }
                setTower(hight - 1, with, to, from);


        }
}
