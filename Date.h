#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date {
		
	public:
		//constructor
		Date();
		Date(int year, int month, int day);
		Date(const Date&);

		~Date();
		
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(const Date&);
		
		//getters
		int getDay();
		int getMonth();
		int getYear();
		string getMonthName();
		
		//other
		void print();
		//comparison operators
		bool lessThan(const Date&);
		bool equals(const Date&);
	
	private:
		//functions
		int getMaxDay();	
	
		//variables
		int day;
		int month;
		int year;
	
};
#endif
