/*
 * main.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: marceldomagala
 */

#define ILTABLIC 100

#include <iostream>
#include "badania.h"
#include "komunikaty.h"

int main()
{

	Komunikat_powitalny();

	//badania dla 100 tablic 10 000 elem.:

	Komunikat_ile_elementow(10000);
	Komunikat_sortowanie_losowe();
	Badanie(ILTABLIC,10000,0);
	Komunikat_sortowanie_procentowe(250);
	Badanie(ILTABLIC,10000,250);
	Komunikat_sortowanie_procentowe(500);
	Badanie(ILTABLIC,10000,500);
	Komunikat_sortowanie_procentowe(750);
	Badanie(ILTABLIC,10000,750);
	Komunikat_sortowanie_procentowe(950);
	Badanie(ILTABLIC,10000,950);
	Komunikat_sortowanie_procentowe(990);
	Badanie(ILTABLIC,10000,990);
	Komunikat_sortowanie_procentowe(997);
	Badanie(ILTABLIC,10000,997);
	Komunikat_sortowanie_odwrotne();
	Badanie_odwrotnie_posortowana(ILTABLIC,10000);

	std::cerr << "/";

	//badania dla 100 tablic 50 000 elem.:

	Komunikat_ile_elementow(50000);
	Komunikat_sortowanie_losowe();
	Badanie(ILTABLIC,50000,0);
	Komunikat_sortowanie_procentowe(250);
	Badanie(ILTABLIC,50000,250);
	Komunikat_sortowanie_procentowe(500);
	Badanie(ILTABLIC,50000,500);
	Komunikat_sortowanie_procentowe(750);
	Badanie(ILTABLIC,50000,750);
	Komunikat_sortowanie_procentowe(950);
	Badanie(ILTABLIC,50000,950);
	Komunikat_sortowanie_procentowe(990);
	Badanie(ILTABLIC,50000,990);
	Komunikat_sortowanie_procentowe(997);
	Badanie(ILTABLIC,50000,997);
	Komunikat_sortowanie_odwrotne();
	Badanie_odwrotnie_posortowana(ILTABLIC,50000);

	std::cerr << "/";

	//badania dla 100 tablic 100 000 elem.:

	Komunikat_ile_elementow(100000);
	Komunikat_sortowanie_losowe();
	Badanie(ILTABLIC,100000,0);
	Komunikat_sortowanie_procentowe(250);
	Badanie(ILTABLIC,100000,250);
	Komunikat_sortowanie_procentowe(500);
	Badanie(ILTABLIC,100000,500);
	Komunikat_sortowanie_procentowe(750);
	Badanie(ILTABLIC,100000,750);
	Komunikat_sortowanie_procentowe(950);
	Badanie(ILTABLIC,100000,950);
	Komunikat_sortowanie_procentowe(990);
	Badanie(ILTABLIC,100000,990);
	Komunikat_sortowanie_procentowe(997);
	Badanie(ILTABLIC,100000,997);
	Komunikat_sortowanie_odwrotne();
	Badanie_odwrotnie_posortowana(ILTABLIC,100000);

	std::cerr << "/";

	//badania dla 100 tablic 500 000 elem.:

	Komunikat_ile_elementow(500000);
	Komunikat_sortowanie_losowe();
	Badanie(ILTABLIC,500000,0);
	Komunikat_sortowanie_procentowe(250);
	Badanie(ILTABLIC,500000,250);
	Komunikat_sortowanie_procentowe(500);
	Badanie(ILTABLIC,500000,500);
	Komunikat_sortowanie_procentowe(750);
	Badanie(ILTABLIC,500000,750);
	Komunikat_sortowanie_procentowe(950);
	Badanie(ILTABLIC,500000,950);
	Komunikat_sortowanie_procentowe(990);
	Badanie(ILTABLIC,500000,990);
	Komunikat_sortowanie_procentowe(997);
	Badanie(ILTABLIC,500000,997);
	Komunikat_sortowanie_odwrotne();
	Badanie_odwrotnie_posortowana(ILTABLIC,500000);

	std::cerr << "/";

	//badania dla 100 tablic 1 000 000 elem.:

	Komunikat_ile_elementow(1000000);
	Komunikat_sortowanie_losowe();
	Badanie(ILTABLIC,1000000,0);
	Komunikat_sortowanie_procentowe(250);
	Badanie(ILTABLIC,1000000,250);
	Komunikat_sortowanie_procentowe(500);
	Badanie(ILTABLIC,1000000,500);
	Komunikat_sortowanie_procentowe(750);
	Badanie(ILTABLIC,1000000,750);
	Komunikat_sortowanie_procentowe(950);
	Badanie(ILTABLIC,1000000,950);
	Komunikat_sortowanie_procentowe(990);
	Badanie(ILTABLIC,1000000,990);
	Komunikat_sortowanie_procentowe(997);
	Badanie(ILTABLIC,1000000,997);
	Komunikat_sortowanie_odwrotne();
	Badanie_odwrotnie_posortowana(ILTABLIC,1000000);

	std::cerr << "/";

	return 0;
}





