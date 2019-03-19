/*
 * main.c
 *
 *  Created on: Mar 13, 2019
 *      Author: Marcel Domagała
 */

#include <iostream>
#include <cmath>
#include "sortowanie.h"
#include "komunikaty.h"

int main()
{
	Komunikat_powitalny();
	int N=10000;
	unsigned int tabliczka[N];
	srand((unsigned)time(NULL));
//	for(int i = 0; i < N; i++) tabliczka[i] = rand();
//	for(int i = 0; i < N; i++) std::cout <<"\t"<< tabliczka[i];
//	std::cout << std::endl;
	double czas = 0;
	clock_t start, stop;
	start = clock();
	//Przez_scalanie(tabliczka,0,N-1);
	//Quick_sort(tabliczka,0,N-1);
	//Hybrid_Introspective_Sort(tabliczka,N);
	//Bubble_sort(tabliczka,N);
	//Odwrocenie(tabliczka,N);
	for(int i=0; i<100; i++){
		int * tablica = new int[N];
		for(int j = 0; j < N; j++) tablica[j] = rand();
		Quick_sort(tabliczka,0,N-1);
		delete [] tablica;
	}
	stop = clock();
	czas = (double)(stop - start) / CLOCKS_PER_SEC;


	std::cout << "po sortowaniu: " << std::endl;
//	for(int i = 0; i < N; i++) std::cout <<"\t"<< tabliczka[i];
//	std::cout << std::endl;
	if(Czy_rosnaco(tabliczka,N)) std::cout << "Posortowane rosnaco!" << std::endl;
	if(Czy_malejaco(tabliczka,N)) std::cout << "Posortowane malejaco!" << std::endl;
	std::cout << "DONE time spend: " << czas << "s"<<std::endl;
	return 0;
}

// POMIAR CZASU:

//	double czas = 0;
//	clock_t start, stop;
//	start = clock();
//	stop = clock();
//	czas = (double)(stop - start) / CLOCKS_PER_SEC;

