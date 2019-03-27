/*
 * sort_szybkie.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#include <iostream>
#include "sort_szybkie.h"

//zbior funkcji realizujacych algorytm sortowania szybkiego

void Sortowanie_szybkie(unsigned int *tablica, int p, int r) 		//sortowanie szybkie
{
	int q;
	if (p < r) {
		q = Partycjonowanie(tablica, p, r); 						//dzielimy tablice na dwie czesci
		Sortowanie_szybkie(tablica, p, q); 							//wywolujemy sortowanie szybkie dla pierwszej czesci tablicy
		Sortowanie_szybkie(tablica, q + 1, r); 						//wywolujemy sortowanie szybkie dla drugiej czesci tablicy
	}
}

int Partycjonowanie(unsigned int * tablica, int lewy, int prawy)
{
	int x = tablica[lewy];
	int i = lewy, j = prawy, w;
	while (true) 													//tyko return wychodzi z petli nieskonczonej
	{
		while (tablica[j] > x)
			j--;
		while (tablica[i] < x)
			i++;
		if (i < j) 													//zamieniana miejscami gdy i < j
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		} else														//gdy i >= j zwracamy j jako punkt podzialu tablicy
			return j;
	}
}


