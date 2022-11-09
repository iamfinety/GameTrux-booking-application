#include "GameTrux.h"

GameTrux::GameTrux(){
    number = 0;
}
GameTrux::~GameTrux(){
    for (int i = 0; i < number; i++) {
    delete trucks[i];
    }
}
bool GameTrux::addTruck(string name, string gameType, int capacity, bool vr){
    if(number >= MAX_TRUCKS){
        return false;
    }
    Truck* truck = new Truck(name, gameType, capacity, vr);
    int index = 0;
    while(index < number){
        if(truck->getName() < (trucks[index]->getName())){
            break;
        }
        ++index;
    }
    for(int i = number; i> index; --i){
        trucks[i] = trucks[i-1];
    }
    trucks[index] = truck;
    ++ number;
    return true;
}
    

bool GameTrux::deleteTruck(string name){
    int index = 0;
    while (index < number){
        if(name.compare(trucks[index]->getName()) == 0){
            break;
        }
        ++index;
    }
    if (index == number) return false;
    delete trucks[index];
    while (index < number-1){
        trucks[index] = trucks[index+1];
        ++index;
    }
    --number;
    return true;

}
void GameTrux::getTruck(int index, Truck** truck){
    if(truck[index] == NULL){
        *truck = NULL;
    }
    *truck = trucks[index];
    
}
bool GameTrux::addReservation(string customer, string gameType, int capacity, bool vr, Date& date, int start, int end){
    for(int i = 0; i < this->number; ++i) {
        if(trucks[i]->isMatch(gameType, capacity, vr)){
            trucks[i]->addReservation(customer, date, start, end);
            return true;
        }
    
    }
    return false;
}
void GameTrux::print(){
    for (int i =0; i < number; ++i){
        trucks[i]->print();
    }
}
void GameTrux::printReservations(){
    for (int i =0; i < number; ++i){
        trucks[i]->print();
        trucks[i]->printReservations();
    }
}