/*
 * komunikaty.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#include <iostream>
#include "komunikaty.h"

//zbior funkcji realizujacych wyswietlanie na std wyjsciu komunikatow

void Komunikat_powitalny()
{
	std::cout << std::endl;
	std::cout << "Program do analizy algorytmów sortowania, dla 100 tablic typu calkowitoliczbowego (integer)" << std::endl;
	std::cout << "o rozmiarach: 10 000, 50 000, 100 000, 500 000, 1 000 000 wykonuje eksperymenty sortowania" << std::endl;
	std::cout << "(sortowanie przez scalanie, sortowanie szybkie, sortowanie introspektywne) w nastepujacych" << std::endl;
	std::cout << "przypadkach:" << std::endl;
	std::cout << "- wszystkie elementy tablicy losowe," << std::endl;
	std::cout << "- 25%; 50%; 75%; 95%; 99%; 99,7% początkowych elementów tablicy jest już posortowanych," << std::endl;
	std::cout << "- wszystkie elementy tablicy już posortowane ale w odwrotnej kolejnosci." << std::endl;
	std::cout << std::endl;
}

void Komunikat_wynik_sort_szybkie(double czas, int il_tablic)
{
	std::cout << "\t\tWyniki dla sortowania szybkiego: " << il_tablic << " tablic posortowano w czasie: \t\t"<< czas << " sekund." << std::endl;
}

void Komunikat_wynik_sort_przez_scalanie(double czas, int il_tablic)
{
	std::cout << "\t\tWyniki dla sortowania przez scalanie: " << il_tablic << " tablic posortowano w czasie: \t\t"<< czas << " sekund." << std::endl;
}

void Komunikat_wynik_sort_introspektywne(double czas, int il_tablic)
{
	std::cout << "\t\tWyniki dla sortowania introspektywnego: " << il_tablic << " tablic posortowano w czasie: \t"<< czas << " sekund." << std::endl;
}

void Komunikat_sortowanie_procentowe(int procent)
{
	std::cout << std::endl;
	std::cout << "\tWyniki dla sortowania, gdzie " << procent/10 << "% elementow poczatkowych bylo juz posortownych:"<< std::endl;
	std::cout << std::endl;
}

void Komunikat_sortowanie_odwrotne()
{
	std::cout << std::endl;
	std::cout << "\tWyniki dla elementow juz posorowanych, ale w odwrotnej kolejnosci:"<< std::endl;
	std::cout << std::endl;
}

void Komunikat_sortowanie_losowe()
{
	std::cout << std::endl;
	std::cout << "\tWyniki dla elementow losowych w tablicach:"<< std::endl;
	std::cout << std::endl;
}

void Komunikat_ile_elementow(int il_elementow)
{
	std::cout << std::endl;
	std::cout << "Badania dla tablic o "<< il_elementow <<" elementow."<<  std::endl;
	std::cout << std::endl;
}


