/*
By Soleil Vivero
03/27/22
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <vector>
#include "Money.h"

class Account{
private:
  bool shouldUpdate = false;
  Money balance;
  std::vector<Money> queueDeposits;
  std::vector<Money> queueWithdrawals;

public:
  // constructor
  Account(Money balance);

  // getter
  Money getBalance();

  // methods
  void makeDeposit(const Money& moneyAdded);
  void makeWithdrawal(const Money& moneyTaken);
  void updateBalance();

  // ostream overload
  friend std::ostream& operator<<(std::ostream& stream, Account& other);
};

#endif // ACCOUNT_H
