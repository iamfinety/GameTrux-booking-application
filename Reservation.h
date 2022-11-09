#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Date.h"


using namespace std;

class Reservation{
    public:
        Reservation(string,  const Date&, int, int);
        void setTime(int, int);
        bool overlaps(const Date&, int, int);
        bool overlaps(Reservation&);
        bool lessThan(Reservation&);
        bool lessThan(const Date&, int, int);
        void print();
        ~Reservation();
    private:
        string name;
        Date date;
        int start;
        int end;
};
#endif