#include "Money.h"

//Parameterized constructor to set the private member values to the passed in values
Money::Money(int m_dollars, int m_cents){
	dollars = m_dollars;
	cents = m_cents;
};

//Default constructor to set both private member values to 0
Money::Money(){
	dollars = 0;
	cents = 0;
};

//checks if one value is less than another by converting both to cent values and comparing those
bool Money::operator<(const Money &rhs) const{
	return all_cents() < rhs.all_cents();
};

//checks if one value is greater than another by converting both to cent values and comparing those
bool Money::operator >(const Money &rhs) const{
	return all_cents() > rhs.all_cents();
};

//checks if one value is less than or equal to another by converting both to cent values and comparing those
bool Money::operator <=(const Money &rhs) const{
	return all_cents()<=rhs.all_cents();
};

//checks if one value is greater than or equal to another by converting both to cent values and comparing those
bool Money::operator >=(const Money &rhs) const{
	return all_cents()>=rhs.all_cents();
};

//checks if one value is not equal to another by converting both to cent values and comparing those
bool Money::operator !=(const Money &rhs) const{
	return all_cents()!=rhs.all_cents();
};

//checks if one value is equal to another by convertingboth to cent values and comparing those
bool Money::operator ==(const Money &rhs) const{
	return all_cents()==rhs.all_cents();
};

Money Money::operator +(const Money &rhs) const{
	int centTotal = cents + rhs.get_cents();  //add cent values together
	int dollarTotal = dollars + rhs.get_dollars(); //add dollar values together
	if (centTotal > 100){  //check if the cent total is over 100 (one dollar). if so, convert
		dollarTotal++;
		centTotal = centTotal - 100;
	}
	else{
	}

	Money total (dollarTotal, centTotal); //set a Money type variable to the result
	return total; //return that variable
};


//- operator overload. This could result in a negative, I don't know if that's an issue
Money Money::operator -(const Money &rhs) const{
	int fullTotal = all_cents() - rhs.all_cents(); //convert both to cent values and subtract
	int centTotal = fullTotal % 100; //pull out the cent value using modulo
	int dollarTotal = (fullTotal - centTotal)*0.01; //convert the remainder back to dollars
	Money total (dollarTotal, centTotal); //set variable of type Money to results
	return total; //return that variable
};

// << operator overload
std::ostream& operator <<(std::ostream &os, const Money &money){
	os << "$" << std::setprecision(2) << std::fixed << money.all_cents()*0.01;
	return os;
};

int Money::all_cents() const{
	int dollarValue = dollars*100; //convert dollar values into cents
	int centValue = dollarValue+cents; //add converted value to existing cents
	return centValue; //return the cents
};
