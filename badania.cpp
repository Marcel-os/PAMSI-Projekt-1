/*
 * badania.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

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
		srand( time( NULL ) );
		double czas_pomocniczy = 0;
		double czas_calkowity = 0;
		int posortowane = 0;
		clock_t start, stop;
		for(int i=0; i<il_tablic; i++)
		{
			unsigned int * tablica = new unsigned int[il_elementow];
			for(int j = 0; j < il_elementow; j++) tablica[j] = std::rand()%100;
			//sortowanie wstepne:
			if(!(!procent_posortowanych))
			{
				Sortowanie_szybkie(tablica,0,((il_elementow*procent_posortowanych)/1000)-1);
			}
				std::cout << (il_elementow*procent_posortowanych)/1000 << "/" << std::endl;
				for(int a = 0; a < il_elementow; a++) std::cout <<"\t"<< tablica[a];
				std::cout << std::endl;

			start = clock();
			Sortowanie_szybkie(tablica,0,il_elementow-1);
			//Sortowanie_przez_scalenie(tablica,0,il_elementow-1);
			//Sortowanie_introspektywne(tablica, il_elementow);

			stop = clock();
			if(Czy_rosnaco(tablica, il_elementow)) posortowane++;
			czas_pomocniczy = (double)(stop - start) / CLOCKS_PER_SEC;
			czas_calkowity += czas_pomocniczy;
			delete [] tablica;
		}
		std::cout << std::endl << "czas: " << czas_calkowity << "  il. posortowanych rosnaco tablic: "<< posortowane <<  std::endl;
}
void Badanie_odwrotnie_posortowana(int il_tablic, int il_elementow, int procent_posortowanych)
{

}

// POMIAR CZASU:

//	double czas = 0;
//	clock_t start, stop;
//	start = clock();
//	stop = clock();
//	czas = (double)(stop - start) / CLOCKS_PER_SEC;



