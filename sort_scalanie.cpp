/*
 * sort_scalanie.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

//zbior funkcji realizujacych algorytm sortowania przez scalanie

#include <iostream>
#include "sort_scalanie.h"

void Scalanie(unsigned int *tablica, int lewy, int srodek, int prawy)
{
	int i, j;
	int pomocnicza[prawy+1];										//niezbedna do scalnia jest pomocnicza tablica
	for (i = srodek + 1; i>lewy; i--)
		pomocnicza[i - 1] = tablica[i - 1];							//wypelniamy ja od srodka do lewej
	for (j = srodek; j<prawy; j++)
		pomocnicza[prawy + srodek - j] = tablica[j + 1];			//nastepnie od srodka do prawej
	for (int k = lewy; k <= prawy; k++)
		if (pomocnicza[j]<pomocnicza[i])							//wpisanie tablicy pomocniczej do tablicy wlasciwej
			tablica[k] = pomocnicza[j--];
		else
			tablica[k] = pomocnicza[i++];
}

void Sortowanie_przez_scalenie(unsigned int *tablica, int lewy, int prawy)
{

	if (prawy <= lewy) return;
	int srodek = (prawy + lewy) / 2;								//wyznaczenie srodka tablicy
	Sortowanie_przez_scalenie(tablica, lewy, srodek);				//sortowanie najperw lewej czesci
	Sortowanie_przez_scalenie(tablica, srodek + 1, prawy);			//a nastepnie prawej czesci
	Scalanie(tablica, lewy, srodek, prawy);							//scalenie dwóch tablic (lewej i prawej) w jedną
}





