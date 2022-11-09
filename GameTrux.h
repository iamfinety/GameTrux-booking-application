#ifndef GAMETRUX_H
#define GAMETRUX_H

#include <iostream>
#include <string>
#include "Truck.h"
#include "Reservation.h"


using namespace std;

class GameTrux{
    public:
        GameTrux();
        ~GameTrux();
        bool addTruck(string, string, int, bool);
        bool deleteTruck(string);
        void getTruck(int, Truck**);
        bool addReservation(string, string, int, bool, Date&, int, int);
        void print();
        void printReservations();
    private:
        Truck* trucks[MAX_TRUCKS];
        int number;
};
#endif