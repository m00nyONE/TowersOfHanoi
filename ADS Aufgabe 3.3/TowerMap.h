#pragma once
#include <string>
#include <iostream>
#include <sstream>

class TowerMap
{
	int** MapCoords;
	int ScheibenAnzahl;


public:
	TowerMap();
	TowerMap(int Scheiben);
	~TowerMap();

	void move(int from, int to);
	void print();
	std::string getValue(int x, int y);
	void clearScreen();


};


