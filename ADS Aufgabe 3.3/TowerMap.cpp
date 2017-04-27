#include "stdafx.h"
#include "TowerMap.h"


TowerMap::TowerMap()
{
	MapCoords = new int*[3];
	for (int i = 0; i < 3; ++i)
		MapCoords[i] = new int[3];

	ScheibenAnzahl = 2;

	for (int i = 0; i <= ScheibenAnzahl; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			MapCoords[j][i] = 0;
		}
	}
	for (int i = ScheibenAnzahl; i >= 0; i--)
	{
		MapCoords[0][i] = i;
	}
}

TowerMap::TowerMap(int Scheiben)
{
	MapCoords = new int*[Scheiben];
	for (int i = 0; i < Scheiben; ++i)
		MapCoords[i] = new int[3];

	ScheibenAnzahl = Scheiben - 1;

	for (int i = 0; i <= ScheibenAnzahl; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			MapCoords[j][i] = 0;
		}
	}
	for (int i = ScheibenAnzahl; i >= 0; i--)
	{
		MapCoords[0][i] = i;
	}
}


TowerMap::~TowerMap()
{
	delete MapCoords;
}

void TowerMap::move(int from, int to)
{

	int tmp = 0;

	for (int i = 0; i <= ScheibenAnzahl; i++)
	{
		if (MapCoords[from][i] != 0)
		{
			tmp = MapCoords[from][i];
			MapCoords[from][i] = 0;
			break;
		}
	}


	for (int j = ScheibenAnzahl; j >= 0; j--)
	{
		if (MapCoords[j][to] == 0)
		{
			MapCoords[j][to] = tmp;
			break;
		}
	}

}

void TowerMap::print()
{
	for (int i = 0; i <= ScheibenAnzahl; i++)
	{
		std::cout << TowerMap::getValue(0, i) << "\t" << TowerMap::getValue(1, i) << "\t" << TowerMap::getValue(2, i) << std::endl;
	}
}

std::string TowerMap::getValue(int x, int y)
{
	int disksize = MapCoords[x][y];
	std::string value = "";
	for (int i = 0; i <= disksize; i++)
	{
		value += "#";
	}
	return value;
}

void TowerMap::clearScreen()
{
	system("cls");
}
