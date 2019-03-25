/*
 * komunikaty.h
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#ifndef KOMUNIKATY_H_
#define KOMUNIKATY_H_

void Komunikat_powitalny();

void Komunikat_wynik_sort_szybkie(double czas, int il_tablic);

void Komunikat_wynik_sort_przez_scalanie(double czas, int il_tablic);

void Komunikat_wynik_sort_introspektywne(double czas, int il_tablic);

void Komunikat_sortowanie_procentowe(int procent);

void Komunikat_sortowanie_odwrotne();

void Komunikat_sortowanie_losowe();

void Komunikat_ile_elementow(int il_elementow);

#endif /* KOMUNIKATY_H_ */
