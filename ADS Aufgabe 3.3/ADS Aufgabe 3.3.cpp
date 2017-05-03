// ADS Aufgabe 3.3.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include "TowerMap.h"

bool showsteps = true;

std::vector<std::vector<int>> _tower(3);

void printTowers();
void setzeTurm(int hight, int from=1, int to=3, int with=2);

int main()
{


	int Scheiben;
	

	std::cout << "Wie viele Scheiben soll der Turm haben? " << std::endl;
	std::cin >> Scheiben;

	for (int i = 0; i<Scheiben; i++)
	{
		_tower[0].push_back(Scheiben - i);
	}

	printTowers();
	std::cout << "##############################################" << std::endl;

	setzeTurm(_tower[0].size());

	std::cout << "##############################################" << std::endl;
	printTowers();


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

void setzeTurm(int hight,int from,int to,int with)
{
	static int Steps;
	if ( hight > 0)
	{
		setzeTurm((hight - 1), from, with, to);
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
		setzeTurm(hight - 1, with, to, from);


	}		
}
