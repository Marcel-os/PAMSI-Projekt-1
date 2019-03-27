/*
 * badania.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#define ZAKRES 10000

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "badania.h"
#include "komunikaty.h"
#include "pomocnicze.h"
#include "sort_scalanie.h"
#include "sort_szybkie.h"
#include "sort_introspektywne.h"

void Badanie(int il_tablic, int il_elementow,int procent_posortowanych)
{
		unsigned int * tablica = new unsigned int[il_elementow];
		srand( time( NULL ) );
		double czas_pomocniczy = 0;
		double czas_calkowity = 0;
		int posortowane = 0;
		clock_t start, stop;

		for(int i=0; i<il_tablic; i++)
		{
			//unsigned int * tablica = new unsigned int[il_elementow];
			for(int j = 0; j < il_elementow; j++) tablica[j] = std::rand()%ZAKRES;
			if(!(!procent_posortowanych))														//sortowanie wstepne
			{
				Sortowanie_introspektywne(tablica,(il_elementow*procent_posortowanych)/1000);
			}

			start = clock();
			Sortowanie_szybkie(tablica,0,il_elementow-1);
			stop = clock();

			if(Czy_rosnaco(tablica, il_elementow)) posortowane++;
			czas_pomocniczy = (double)(stop - start) / CLOCKS_PER_SEC;
			czas_calkowity += czas_pomocniczy;
			//delete [] tablica;
		}
		Komunikat_wynik_sort_szybkie( czas_calkowity, posortowane);

		czas_pomocniczy = 0;
		czas_calkowity = 0;
		posortowane = 0;

		for(int i=0; i<il_tablic; i++)
		{
			//unsigned int * tablica = new unsigned int[il_elementow];
			for(int j = 0; j < il_elementow; j++) tablica[j] = std::rand()%ZAKRES;
			if(!(!procent_posortowanych))														//sortowanie wstepne
			{
				Sortowanie_introspektywne(tablica,(il_elementow*procent_posortowanych)/1000);
			}

			start = clock();
			Sortowanie_przez_scalenie(tablica,0,il_elementow-1);
			stop = clock();

			if(Czy_rosnaco(tablica, il_elementow)) posortowane++;
			czas_pomocniczy = (double)(stop - start) / CLOCKS_PER_SEC;
			czas_calkowity += czas_pomocniczy;
			//delete [] tablica;
		}
		Komunikat_wynik_sort_przez_scalanie( czas_calkowity, posortowane);

		czas_pomocniczy = 0;
		czas_calkowity = 0;
		posortowane = 0;

		for(int i=0; i<il_tablic; i++)
		{
			//unsigned int * tablica = new unsigned int[il_elementow];
			for(int j = 0; j < il_elementow; j++) tablica[j] = std::rand()%ZAKRES;
			if(!(!procent_posortowanych))														//sortowanie wstepne
			{
				Sortowanie_introspektywne(tablica,(il_elementow*procent_posortowanych)/1000);
			}

			start = clock();
			Sortowanie_introspektywne(tablica, il_elementow);
			stop = clock();

			if(Czy_rosnaco(tablica, il_elementow)) posortowane++;
			else std::cerr << "Blad, nie posortowano" << std::endl;
			czas_pomocniczy = (double)(stop - start) / CLOCKS_PER_SEC;
			czas_calkowity += czas_pomocniczy;
			//delete [] tablica;
		}
		Komunikat_wynik_sort_introspektywne(czas_calkowity, posortowane);
		delete [] tablica;
		std::cerr << ".";

}
void Badanie_odwrotnie_posortowana(int il_tablic, int il_elementow)
{
	unsigned int * tablica = new unsigned int[il_elementow];
	srand( time( NULL ) );
	double czas_pomocniczy = 0;
	double czas_calkowity = 0;
	int posortowane = 0;
	clock_t start, stop;

	for(int i=0; i<il_tablic; i++)
	{
		//unsigned int * tablica = new unsigned int[il_elementow];
		for(int j = 0; j < il_elementow; j++) tablica[j] = std::rand()%ZAKRES;

			Sortowanie_introspektywne(tablica, il_elementow);									//sortowanie wstepne
			Odwrocenie(tablica, il_elementow);

		start = clock();
		Sortowanie_szybkie(tablica,0,il_elementow-1);
		stop = clock();

		if(Czy_rosnaco(tablica, il_elementow)) posortowane++;
		else std::cerr << "Blad, nie posortowano" << std::endl;
		czas_pomocniczy = (double)(stop - start) / CLOCKS_PER_SEC;
		czas_calkowity += czas_pomocniczy;
		//delete [] tablica;
	}
	Komunikat_wynik_sort_szybkie( czas_calkowity, posortowane);

	czas_pomocniczy = 0;
	czas_calkowity = 0;
	posortowane = 0;

	for(int i=0; i<il_tablic; i++)
	{
		//unsigned int * tablica = new unsigned int[il_elementow];
		for(int j = 0; j < il_elementow; j++) tablica[j] = std::rand()%ZAKRES;

			Sortowanie_introspektywne(tablica, il_elementow);									//sortowanie wstepne
			Odwrocenie(tablica, il_elementow);

		start = clock();
		Sortowanie_przez_scalenie(tablica,0,il_elementow-1);
		stop = clock();

		if(Czy_rosnaco(tablica, il_elementow)) posortowane++;
		else std::cerr << "Blad, nie posortowano" << std::endl;
		czas_pomocniczy = (double)(stop - start) / CLOCKS_PER_SEC;
		czas_calkowity += czas_pomocniczy;
		//delete [] tablica;
	}
	Komunikat_wynik_sort_przez_scalanie( czas_calkowity, posortowane);

	czas_pomocniczy = 0;
	czas_calkowity = 0;
	posortowane = 0;

	for(int i=0; i<il_tablic; i++)
	{
		//unsigned int * tablica = new unsigned int[il_elementow];
		for(int j = 0; j < il_elementow; j++) tablica[j] = std::rand()%ZAKRES;

			Sortowanie_introspektywne(tablica, il_elementow);									//sortowanie wstepne
			Odwrocenie(tablica, il_elementow);

		start = clock();
		Sortowanie_introspektywne(tablica, il_elementow);
		stop = clock();

		if(Czy_rosnaco(tablica, il_elementow)) posortowane++;
		else std::cerr << "Blad, nie posortowano" << std::endl;
		czas_pomocniczy = (double)(stop - start) / CLOCKS_PER_SEC;
		czas_calkowity += czas_pomocniczy;
		//delete [] tablica;
	}
	Komunikat_wynik_sort_introspektywne( czas_calkowity, posortowane);
	delete [] tablica;
	std::cerr << ".";
}




