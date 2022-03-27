/*
By Soleil Vivero
03/27/22
*/

#include "Account.h"

Account::Account(Money _balance) : balance(_balance) {}

// updates the balance if needed, returns new balance
Money Account::getBalance(){
  if(shouldUpdate){
    updateBalance();
  }
  return balance;
}

// adds Money deposits to the queue vector
void Account::makeDeposit(const Money& moneyAdded){
  shouldUpdate = true;
  queueDeposits.push_back(moneyAdded);
}

// adds Money withdrawals to the queue vector
void Account::makeWithdrawal(const Money& moneyTaken){
  shouldUpdate = true;
  queueWithdrawals.push_back(moneyTaken);
}

// calculates new balance according to the values in both vector queues
void Account::updateBalance(){
  for(Money value: queueDeposits){
    balance = balance + value;
  }
  for(Money value: queueWithdrawals){
    balance = balance - value;
  }
  shouldUpdate = false;
}

// makes it possible to print Account objects + sets it in a specific format
std::ostream& operator<<(std::ostream& stream, Account& other){
  int deposits = other.queueDeposits.size();  // amount of deposits made
  int withdrawals = other.queueWithdrawals.size();  // amount of withdrawals made

  stream << "Account Details\n--------------------------" << std::endl;
  stream << "Current Balance: " << other.getBalance() << std::endl;
  stream << "--------------------------" << std::endl;
  stream << "Number of Deposits: " << deposits << std::endl;
  stream << "--------------------" << std::endl;

  if(deposits == 0){
    stream << "No deposits made" << std::endl;
  } else{
    for(int i = 0; i < deposits; i++){
      // format like "(1) $100.33"
      stream << "(" << i + 1 << ") " << other.queueDeposits.at(i) << std::endl;
    }
  }

  stream << "--------------------------" << std::endl;
  stream << "Number of Withdrawals: " << withdrawals << std::endl;
  stream << "--------------------------" << std::endl;

  if(withdrawals == 0){
    stream << "No withdrawals made" << std::endl;
  } else{
    for(int i = 0; i < withdrawals; i++){
      stream << "(" << i + 1 << ") " << other.queueWithdrawals.at(i) << std::endl;
    }
  }

  // clear queues for next withdrawal and deposit
  other.queueDeposits.clear();
  other.queueWithdrawals.clear();

  return stream;
}
