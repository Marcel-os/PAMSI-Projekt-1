/*
 * sort_szybkie.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#include <iostream>
#include "sort_szybkie.h"

void Sortowanie_szybkie(unsigned int *tablica,int lewy, int prawy)
{
  int i,j,srodek;

  i = (lewy + prawy) / 2;
  srodek = tablica[i];
  tablica[i] = tablica[prawy];
  for(j = i = lewy; i < prawy; i++)
	  if(tablica[i] < srodek)
	  {
		  std::swap(tablica[i], tablica[j]);
		  j++;
	  }
  tablica[prawy] = tablica[j];
  tablica[j] = srodek;
  if(lewy < j - 1)  Sortowanie_szybkie(tablica, lewy, j - 1);
  if(j + 1 < prawy) Sortowanie_szybkie(tablica, j + 1, prawy);
}



