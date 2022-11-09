#include "Reservation.h"

Reservation::Reservation(string name, const Date& d, int start, int end){
    this->name = name;
    date.setDate(d);
    this->start = start;
    this->end = end;
}
Reservation::~Reservation(){
	
}
void Reservation::setTime(int start, int end){
    if(start < 8) start = 8;
    if(end > 22) end = 22;
    if(start > end-1){
        start = end -1;
    }
    this->start = start;
    this->end = end;
}
bool Reservation::overlaps(const Date& d, int start, int end){
    if(date.equals(d)){
        if(this->start <= start){
            if(this->end > start){
                return true;
            }
        }
        else if(this->start >= start){
            if(end > this->start){
                return true;
            }
        }
        else{
            return false;
        }
    }
    
    return false;
    
    

}
bool Reservation::overlaps(Reservation& r){
    if(date.equals(r.date)){
        if(this->start < r.start){
            if(this->end > r.start){
                return true;
            }
        }
        else if(this->start > r.start){
            if(r.end > this->start){
                return true;
            }
        }
        else{
            return false;
        }
    }

    return false;
    
}

bool Reservation::lessThan(const Date& d, int start, int end){
    if(overlaps(d, start, end)){
        return false;
    }
    if(date.lessThan(d)){
        return true;
    }
    else if(date.equals(d)){
        if(this->start < start){
            return true;
        }
    }
    return false;
}
bool Reservation::lessThan(Reservation& res){
    if(overlaps(res.date, res.start, res.end)){
        return false;
    }
    if(date.lessThan(res.date)){
        return true;
    }
    else if(date.equals(res.date)){
        if(this->start < res.start){
            return true;
        }
    }
    return false;
}
void Reservation::print(){
    
    cout << "Reservation for " << name<<" on ";
    date.print();
    cout <<" from "<<start<<":00"<<" to "<<end<<":00"<<endl;
} 