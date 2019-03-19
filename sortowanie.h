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
void Przez_scalanie(unsigned int *tab, int lewy, int prawy);
////////////////////////////////////////////////////////////////
void Hybrid_Introspective_Sort(unsigned int *Array, int N);
void IntroSort (unsigned int *Array, int N, int M);
int Partition (unsigned int *Array, int L, int R);
void MedianOfThree (unsigned int *Array, int &L, int &R);
void Exchange (unsigned int *Array, int i, int j);
void Heap_Sort (unsigned int *Array, int N);
void Heapify (unsigned int *Array, int i, int N);
void Insertion_Sort (unsigned int *Array, int N);

#endif /* SORTOWANIE_H_ */
