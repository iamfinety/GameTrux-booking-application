#include "Truck.h"
#include "Reservation.h"
//bool overlaps(const Date&, int, int);

Truck::Truck(string name, string gameType, int capacity, bool vr){
    this->name = name;
    this->gameType = gameType;
    this->capacity = capacity;
    this->vr = vr;
    this->number = 0;

}
Truck::~Truck(){
    for (int i = 0; i < number; i++) {
    delete reservations[i];
    }
}
string Truck::getName(){
    return name;
}
bool Truck::isMatch(string gt, int cap, bool v){
    if(gameType.compare(gt) == 0){
        if(capacity >= cap){
            if(v == true){
                if(vr == true){
                    return true;
                }
            }
            else if(v == false){
                if(vr == true || vr == false){
                    return true;
                }
            }
        }
    }
    return false;
}
bool Truck::lessThan(Truck& t){
    if(t.name > this->name){
        return true;
    }
    return false;
}
bool Truck::addReservation(string customerName, Date& d, int start, int end){
    if(number >= MAX_RES){
        return false;
    }
    
    int index = 0;
    for( int i=number; i> index; i--){
        if(reservations[i]->overlaps(d, start, end)){
            return false;
        }    
        else{
            Reservation* reservation = new Reservation(customerName, d, start, end);
            if(reservation->lessThan(*reservations[index]) ){
                reservations[i] = reservations[i-1];
                reservations[index] = reservation;
                ++number;
                return true;
            

            }
        
        }
        
    }
    
    return false;
    

}                                    
    

void Truck::print(){
    cout << this->getName()<<"type is "<< this->gameType<<" capacity "<< this->capacity <<endl;
}
void Truck::printReservations(){
    this->print();
    for (int i =0; i < number; ++i){
        reservations[i]->print();
    }
}