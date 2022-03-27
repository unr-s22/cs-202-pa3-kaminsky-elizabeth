#include <iostream>
#include <iomanip>

#ifndef MONEY_H
#define MONEY_H

class Money {
private:
	int dollars; //will store dollars as an integer value
	int cents; //will store cents as an integer value

public:
	Money( int m_dollars, int m_cents ); //parameterized constructor intitialization
	Money(); //default constructor initialization

	//overload of < operator initialization
	bool operator<(const Money &rhs) const;

	//overload of > operator initialization
	bool operator >(const Money &rhs) const;

	//overload of <= operator initialization
	bool operator <=(const Money &rhs) const;

	//overload of >= operator initialization
	bool operator >=(const Money &rhs) const;

	//overload of != operator initialization
	bool operator !=(const Money &rhs) const;

	//overload of == operator initialization
	bool operator ==(const Money &rhs) const;

	//overload of + operator initialization
	Money operator +(const Money &rhs) const;

	//overload of - operator initialization
	Money operator -(const Money &rhs) const;

	//overload of << operator initialization
	friend std::ostream& operator <<(std::ostream &os, const Money &money);

	//an all_cents function initialization
	int all_cents() const;

	//Getters
	int get_dollars() const{return dollars;};
	int get_cents() const{return cents;};

	//Setters
	void set_dollars(int m) {dollars = m;};
	void set_cents(int m) {cents = m;};
};

#endif
