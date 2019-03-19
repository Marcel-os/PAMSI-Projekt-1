/*
 * sortowanie.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: Marcel Domagała
 */
#include <iostream>
#include <math.h>
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

void Przez_scalanie(unsigned int *tab, int lewy, int prawy)
{
	//gdy mamy jeden element, to jest on juz posortowany
	if (prawy <= lewy) return;

	//znajdujemy srodek podtablicy
	int srodek = (prawy + lewy) / 2;

	//dzielimy tablice na czesc lewa i prawa
	Przez_scalanie(tab, lewy, srodek);
	Przez_scalanie(tab, srodek + 1, prawy);

	//scalamy dwie posortowane tablice
	scalanie(tab, lewy, srodek, prawy);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void Hybrid_Introspective_Sort(unsigned int *Array, int N)
{
  IntroSort(Array,N,(int)floor(2*log(N)/M_LN2));
  Insertion_Sort(Array,N);
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






