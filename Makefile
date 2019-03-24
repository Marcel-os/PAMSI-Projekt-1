__start__: a.out
#	./a.out >wyniki.txt
	./a.out
	
a.out: main.o badania.o pomocnicze.o sort_scalanie.o sort_szybkie.o sort_introspektywne.o komunikaty.o
	g++ main.o badania.o pomocnicze.o sort_scalanie.o sort_szybkie.o sort_introspektywne.o komunikaty.o

main.o: main.cpp badania.h
	g++ -c -g -Iinc -Wall -pedantic main.cpp

badania.o: badania.h pomocnicze.h sort_scalanie.h sort_szybkie.h sort_introspektywne.h komunikaty.h badania.cpp
	g++ -c -Wall -pedantic badania.cpp
	
pomocnicze.o: pomocnicze.h pomocnicze.cpp
	g++ -c -Wall -pedantic pomocnicze.cpp

sort_scalanie.o: sort_scalanie.h sort_scalanie.cpp
	g++ -c -Wall -pedantic sort_scalanie.cpp

sort_szybkie.o: sort_szybkie.h sort_szybkie.cpp
	g++ -c -Wall -pedantic sort_szybkie.cpp

sort_introspektywne.o: sort_introspektywne.h sort_introspektywne.cpp
	g++ -c -Wall -pedantic sort_introspektywne.cpp
	
komunikaty.o: komunikaty.h komunikaty.cpp
	g++ -c -Wall -pedantic komunikaty.cpp
