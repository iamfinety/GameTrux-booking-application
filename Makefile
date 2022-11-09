all: a1

a1: main.o Date.o GameTrux.o  Reservation.o Truck.o
	g++ -o a1 main.o Date.o GameTrux.o  Reservation.o Truck.o

main.o: main.cc Truck.h	GameTrux.h Reservation.h
	g++ -c main.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc

GameTrux.o: GameTrux.cc Truck.h Reservation.h
	g++ -c GameTrux.cc
	
Truck.o: Truck.h Truck.cc Date.o 
	g++ -c Truck.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc
	
clean:
	rm -f *.o a1