// ADS Aufgabe 3.3.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include "TowerMap.h"

void Ziehe(int von, int nach, int ScheibenZahl, TowerMap tower);

int main()
{

	

	int Scheiben;


	std::cout << "Wie viele Scheiben soll der Turm haben? " << std::endl;
	std::cin >> Scheiben;

	TowerMap tower(Scheiben);
	TowerMap*ptr = &tower;

	Ziehe(1, 3, Scheiben, tower); // from 1 to 3, n Scheiben

	system("pause");
	return 0;
}


void Ziehe(int from, int to, int ScheibenZahl, TowerMap tower)
{

	static int GlobaleAnzahl = 1;

	if (ScheibenZahl == 0) return;
	int frei = 6 - from - to;    // bestimme den freien Platz - einfache Methode ( siehe Wikipedia )
	Ziehe(from, frei, ScheibenZahl - 1, tower);

	std::cout << "Zug " << GlobaleAnzahl << ": " << from << " - " << to << std::endl;
	tower.move(from -1, to -1);
	tower.print();

	GlobaleAnzahl++;
	Ziehe(frei, to, ScheibenZahl - 1, tower);


}

/*
Anzahl der Züge = max Zahl in Bit -2
*/
