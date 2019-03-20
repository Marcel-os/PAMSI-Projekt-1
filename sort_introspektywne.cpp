/*
 * sort_introspektywne.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#include <iostream>
#include <math.h>
#include "sort_introspektywne.h"

void Sortowanie_introspektywne(unsigned int *tablica, int dlugosc)
{
  IntroSort(tablica,dlugosc,(int)floor(2*log(dlugosc)/M_LN2));
  Insertion_Sort(tablica,dlugosc);
}

void IntroSort (unsigned int *Array, int N, int M)
{
  int i;
  if (M<=0)
  {
    Heap_Sort(Array,N);
    return;
  }
  i=Partition(Array,0,N);
  if (i>9)
    IntroSort(Array,i,M-1);
  if (N-1-i>9)
    IntroSort(Array+i+1,N-1-i,M-1);
}

int Partition (unsigned int *Array, int L, int R)
{
  int i, j;
  if (R>=3)
    MedianOfThree(Array,L,R);
  for (i=L, j=R-2; ; )
  {
    for ( ; Array[i]<Array[R-1]; ++i);
    for ( ; j>=L && Array[j]>Array[R-1]; --j);
    if (i<j)
      Exchange(Array,i++,j--);
    else break;
  }
  Exchange(Array,i,R-1);
  return i;
}

void MedianOfThree (unsigned int *Array, int &L, int &R)
{
  if (Array[++L-1]>Array[--R])
    Exchange(Array,L-1,R);
  if (Array[L-1]>Array[R/2])
    Exchange(Array,L-1,R/2);
  if (Array[R/2]>Array[R])
    Exchange(Array,R/2,R);
  Exchange(Array,R/2,R-1);
}

void Exchange (unsigned int *Array, int i, int j)
{
  int temp;
  temp=Array[i];
  Array[i]=Array[j];
  Array[j]=temp;
}

void Heap_Sort (unsigned int *Array, int N)
{
  int i;
  for (i=N/2; i>0; --i)
    Heapify(Array-1,i,N);
  for (i=N-1; i>0; --i)
  {
    Exchange(Array,0,i);
    Heapify(Array-1,1,i);
  }
}

void Heapify (unsigned int *Array, int i, int N)
{
  int j;
  while (i<=N/2)
  {
    j=2*i;
    if (j+1<=N && Array[j+1]>Array[j])
      j=j+1;
    if (Array[i]<Array[j])
      Exchange(Array,i,j);
    else break;
    i=j;
  }
}

void Insertion_Sort (unsigned int *Array, int N)
{
  int i, j;
  int temp;
  for (i=1; i<N; ++i)
  {
    temp=Array[i];
    for (j=i; j>0 && temp<Array[j-1]; --j)
      Array[j]=Array[j-1];
    Array[j]=temp;
  }
}




