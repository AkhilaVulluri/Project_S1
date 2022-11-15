output: bus_main.o email.o star.o
	g++ bus_main.o email.o star.o  -o output
main.cpp: bus_main.cpp
	g++ bus_main.cpp –o bus_main
email.o:email.h
	g++ email.h –o email
star.o:star.h
	g++ star.h –o star
clear:
	rm -f bus_main.o email.o star.o
