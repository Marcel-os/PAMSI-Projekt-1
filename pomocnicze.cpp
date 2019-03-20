/*
 * pomocnicze.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#include <iostream>
#include <math.h>
#include "pomocnicze.h"

void Sortowanie_babekowe(unsigned int *tablica, int dlugosc)
{
	  for(int j = 0; j < dlugosc - 1; j++)
	    for(int i = 0; i < dlugosc - 1; i++)
	      if(tablica[i] > tablica[i + 1]) std::swap(tablica[i], tablica[i + 1]);
}

void Odwrocenie(unsigned int *tablica, int dlugosc)
{
	for(int i = 0; i < (dlugosc)/2; i++) std::swap(tablica[i], tablica[(dlugosc-1)-i]);
}

bool Czy_rosnaco(unsigned int *tablica, int dlugosc)
{
	  for(int i = 0; i < dlugosc - 1; i++)
	    if(tablica[i] > tablica[i + 1]) return 0;
	    return 1;
}

bool Czy_malejaco(unsigned int *tablica, int dlugosc)
{
	  for(int i = 0; i < dlugosc - 1; i++)
	    if(tablica[i] < tablica[i + 1]) return 0;
	    return 1;
}




