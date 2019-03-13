/*
 * sortowanie.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: Marcel Domagała
 */
#include <iostream>
#include "sortowanie.h"

void Bubble_sort(unsigned int *tab, int length)
{
	  for(int j = 0; j < length - 1; j++)
	    for(int i = 0; i < length - 1; i++)
	      if(tab[i] > tab[i + 1]) std::swap(tab[i], tab[i + 1]);
}

void Odwrocenie(unsigned int *tab, int length)
{
	for(int i = 0; i < (length)/2; i++) std::swap(tab[i], tab[(length-1)-i]);
}

bool Czy_rosnaco(unsigned int *tab, int length)
{
	  for(int i = 0; i < length - 1; i++)
	    if(tab[i] > tab[i + 1]) return 0;
	    return 1;
}

bool Czy_malejaco(unsigned int *tab, int length)
{
	  for(int i = 0; i < length - 1; i++)
	    if(tab[i] < tab[i + 1]) return 0;
	    return 1;
}

void Quick_sort(unsigned int *tab,int left, int right)
{
  int i,j,center;

  i = (left + right) / 2;
  center = tab[i];
  tab[i] = tab[right];
  for(j = i = left; i < right; i++)
  if(tab[i] < center)
  {
    std::swap(tab[i], tab[j]);
    j++;
  }
  tab[right] = tab[j]; tab[j] = center;
  if(left < j - 1)  Quick_sort(tab, left, j - 1);
  if(j + 1 < right) Quick_sort(tab, j + 1, right);
}

//void Merge_sort(unsigned int *tab, int left, int right)
//{
//  int i_s,i1,i2,i;
//  unsigned int tab_pomoc[right+1];
//
//  i_s = (left + right + 1) / 2;
//  if(i_s - left > 1) Merge_sort(tab, left, i_s - 1);
//  if(right - i_s > 0) Merge_sort(tab, i_s, right);
//  i1 = left; i2 = i_s;
//  for(i = left; i <= right; i++)
//	  tab_pomoc[i] = ((i1 == i_s) || ((i2 <= right) && (tab[i1] > tab[i2]))) ? tab[i2++] : tab[i1++];
//  for(i = left; i <= right; i++) tab[i] = tab_pomoc[i];
//}

void scalanie(unsigned int *tab, int lewy, int srodek, int prawy)
{
	int i, j;
	int pomocnicza[1000000];

	//zapisujemy lewą częsć podtablicy w tablicy pomocniczej
	for (i = srodek + 1; i>lewy; i--)
		pomocnicza[i - 1] = tab[i - 1];

	//zapisujemy prawą częsć podtablicy w tablicy pomocniczej
	for (j = srodek; j<prawy; j++)
		pomocnicza[prawy + srodek - j] = tab[j + 1];

	//scalenie dwóch podtablic pomocniczych i zapisanie ich
	//we własciwej tablicy
	for (int k = lewy; k <= prawy; k++)
		if (pomocnicza[j]<pomocnicza[i])
			tab[k] = pomocnicza[j--];
		else
			tab[k] = pomocnicza[i++];
}

void Merge_sort(unsigned int *tab, int lewy, int prawy)
{
	//gdy mamy jeden element, to jest on juz posortowany
	if (prawy <= lewy) return;

	//znajdujemy srodek podtablicy
	int srodek = (prawy + lewy) / 2;

	//dzielimy tablice na czesc lewa i prawa
	Merge_sort(tab, lewy, srodek);
	Merge_sort(tab, srodek + 1, prawy);

	//scalamy dwie posortowane tablice
	scalanie(tab, lewy, srodek, prawy);
}





