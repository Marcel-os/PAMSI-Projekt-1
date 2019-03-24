/*
 * sort_introspektywne.h
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#ifndef SORT_INTROSPEKTYWNE_H_
#define SORT_INTROSPEKTYWNE_H_

void Sortowanie_introspektywne(unsigned int *tablica, int dlugosc);

void IntroSort (unsigned int *Array, int N, int M);

int Partition (unsigned int *Array, int L, int R);

void MedianOfThree (unsigned int *Array, int &L, int &R);

void Exchange (unsigned int *Array, int i, int j);

void Heap_Sort (unsigned int *Array, int N);

void Heapify (unsigned int *Array, int i, int N);

void Insertion_Sort (unsigned int *Array, int N);

#endif /* SORT_INTROSPEKTYWNE_H_ */
