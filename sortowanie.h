/*
 * sortowanie.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Marcel Domagała
 */

#ifndef SORTOWANIE_H_
#define SORTOWANIE_H_

#include <iostream>

void Bubble_sort(unsigned int *tab, int length);
void Odwrocenie(unsigned int *tab, int length);
bool Czy_rosnaco(unsigned int *tab, int length);
bool Czy_malejaco(unsigned int *tab, int length);
void Quick_sort(unsigned int *tab,int left, int right);
//void Merge_sort(unsigned int *tab, int left, int right);
void scalanie(unsigned int *tab, int lewy, int srodek, int prawy);
void Merge_sort(unsigned int *tab, int lewy, int prawy);

#endif /* SORTOWANIE_H_ */
