
__start__: a.out
	./a.out
	
a.out: main.o sortowanie.o komunikaty.o
	g++ main.o sortowanie.o komunikaty.o

main.o: main.cpp sortowanie.h komunikaty.h
	g++ -c -g -Iinc -Wall -pedantic main.cpp
	
sortowanie.o: sortowanie.h sortowanie.cpp
	g++ -c -Wall -pedantic sortowanie.cpp

komunikaty.o: komunikaty.h komunikaty.cpp
	g++ -c -Wall -pedantic komunikaty.cpp
