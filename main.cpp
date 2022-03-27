/*
By Soleil Vivero
03/27/22
*/

#include "Money.h"
#include "Account.h"

int main(){
	Money start(300, 23);
	Money deposit1(200, 00);
	Money deposit2(300, 24);
	Money deposit3(501, 22);
	Money withdrawal1(300, 10);
	Money withdrawal2(201, 34);
	Account account(start);  // define account with an initial money value

	std::cout << account << std::endl;

	account.makeDeposit(deposit1);
	account.makeDeposit(deposit2);
	account.makeDeposit(deposit3);

	std::cout << account << std::endl;

	account.makeWithdrawal(withdrawal1);
	account.makeWithdrawal(withdrawal2);

	std::cout << account << std::endl;

	// proof that operator overloads work
	Money x(10, 50);
	Money y(9, 30);
	Money z(10, 50);
	if(x == z){std::cout << x << " and " << z << " are the same" <<std::endl;}
	if(x != y){std::cout << x << " and " << y << " are not the same" <<std::endl;}
	if(x > y){std::cout << x << " is greater than " << y <<std::endl;}
	if(y < x){std::cout << y << " is less than " << x << std::endl;}
	if(x >= z){std::cout << x << " is greater than or equal to " << z <<std::endl;}
	if(x <= z){std::cout << x << " is less than or equal to " << z <<std::endl;}

	return 0;
}
