/*
 * sort_introspektywne.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

//zbior funkcji realizujacych algorytm sortowania introspektywnego

#include <iostream>
#include <math.h>
#include "sort_introspektywne.h"
#include "sort_szybkie.h"

void Sortowanie_introspektywne(unsigned int *tablica, int dlugosc)
{
	Sortowanie_introspektywne_dalej(tablica,dlugosc,(int)floor(2*log(dlugosc)/M_LN2));
	Sortowanie_prez_wstawianie(tablica,dlugosc);					//dla prawie posortowanej tablicy wywołuje się sortowanie przez wstawianie
}

void Sortowanie_introspektywne_dalej(unsigned int *tablica, int dlugosc, int M)
{
	int i;
	if (M<=0)														//po zrealizowaniu 2∙log2n wywołań rekurencyjnych sortujemy dalej przez kopcowanie
	{
		Sortowanie_przez_kopcowanie(tablica,dlugosc);
		return;
	}
	i=Partycjonowanie(tablica,0,dlugosc-1);
	if (i>9)
		Sortowanie_introspektywne_dalej(tablica,i,M-1);
	if (dlugosc-1-i>9)
		Sortowanie_introspektywne_dalej(tablica+i+1,dlugosc-1-i,M-1);
}

void Sortowanie_przez_kopcowanie(unsigned int *tablica, int dlugosc)
{
	int i;
	for (i=dlugosc/2; i>0; --i)
		Kopiec(tablica-1,i,dlugosc);
	for (i=dlugosc-1; i>0; --i)
	{
		std::swap(tablica[0], tablica[i]);
		Kopiec(tablica-1,1,i);
	}
}

void Kopiec(unsigned int *tablica, int i, int dlugosc)
{
	int j;
	while (i<=dlugosc/2)
	{
		j=2*i;
		if (j+1<=dlugosc && tablica[j+1]>tablica[j])
			j=j+1;
		if (tablica[i]<tablica[j]) std::swap(tablica[i], tablica[j]);				//zamiana elemetu wiekszego i mniejszego w kopcu
		else break;
		i=j;
	}
}

void Sortowanie_prez_wstawianie(unsigned int *tablica, int dlugosc)
{
	int i, j;
	int temp;
	for (i=1; i<dlugosc; ++i)
	{
		temp=tablica[i];
		for (j=i; j>0 && temp<tablica[j-1]; --j)					//dopoki j>0 i element tablicy o indeksiej jest mniejszy od wstawianego elemetu
			tablica[j]=tablica[j-1];
		tablica[j]=temp;
	}
}





