#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Reservation.h"
#include "Date.h"

using namespace std;
class Truck{
    public:
        Truck(string, string, int, bool);
        ~Truck();
        string getName();
        bool isMatch(string, int, bool);
        bool lessThan(Truck&);
        bool addReservation(string, Date&, int, int);
        void printReservations();
        void print();
    private:
        string name;
        string gameType; 
        int capacity;
        bool vr;
        Reservation* reservations[MAX_RES];
        int number;
};
#endif