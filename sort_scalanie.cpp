/*
 * sort_scalanie.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#include <iostream>
#include "sort_scalanie.h"

void Scalanie(unsigned int *tablica, int lewy, int srodek, int prawy)
{
	int i, j;
	int pomocnicza[prawy+1]; //	int pomocnicza[1000000];

	//zapisujemy lewą częsć podtablicy w tablicy pomocniczej
	for (i = srodek + 1; i>lewy; i--)
		pomocnicza[i - 1] = tablica[i - 1];

	//zapisujemy prawą częsć podtablicy w tablicy pomocniczej
	for (j = srodek; j<prawy; j++)
		pomocnicza[prawy + srodek - j] = tablica[j + 1];

	//scalenie dwóch podtablic pomocniczych i zapisanie ich
	//we własciwej tablicy
	for (int k = lewy; k <= prawy; k++)
		if (pomocnicza[j]<pomocnicza[i])
			tablica[k] = pomocnicza[j--];
		else
			tablica[k] = pomocnicza[i++];
}

void Sortowanie_przez_scalenie(unsigned int *tablica, int lewy, int prawy)
{
	//gdy mamy jeden element, to jest on juz posortowany
	if (prawy <= lewy) return;

	//znajdujemy srodek podtablicy
	int srodek = (prawy + lewy) / 2;

	//dzielimy tablice na czesc lewa i prawa
	Sortowanie_przez_scalenie(tablica, lewy, srodek);
	Sortowanie_przez_scalenie(tablica, srodek + 1, prawy);

	//scalamy dwie posortowane tablice
	Scalanie(tab, lewy, srodek, prawy);
}





