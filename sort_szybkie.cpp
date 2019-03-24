/*
 * sort_szybkie.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#include <iostream>
#include "sort_szybkie.h"

//void Sortowanie_szybkie(unsigned int *tablica, int lewy, int prawy) {
//	int i, j, srodek;
//
//	i = (lewy + prawy) / 2;
//	srodek = tablica[i];
//	tablica[i] = tablica[prawy];
//	for (j = i = lewy; i < prawy; i++)
//		if (tablica[i] < srodek) {
//			std::swap(tablica[i], tablica[j]);
//			j++;
//		}
//	tablica[prawy] = tablica[j];
//	tablica[j] = srodek;
//	if (lewy < j - 1)
//		Sortowanie_szybkie(tablica, lewy, j - 1);
//	if (j + 1 < prawy)
//		Sortowanie_szybkie(tablica, j + 1, prawy);
//}

int partition(unsigned int * tablica, int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
		{
	int x = tablica[p]; // obieramy x
	int i = p, j = r, w; // i, j - indeksy w tabeli
	while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
	{
		while (tablica[j] > x) // dopoki elementy sa wieksze od x
			j--;
		while (tablica[i] < x) // dopoki elementy sa mniejsze od x
			i++;
		if (i < j) // zamieniamy miejscami gdy i < j
				{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		} else
			// gdy i >= j zwracamy j jako punkt podzialu tablicy
			return j;
	}
}

void Sortowanie_szybkie(unsigned int * tablica, int p, int r) // sortowanie szybkie
		{
	int q;
	if (p < r) {
		q = partition(tablica, p, r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
		Sortowanie_szybkie(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
		Sortowanie_szybkie(tablica, q + 1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
	}
}

