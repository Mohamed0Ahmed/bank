#pragma once
#include <string>
#include <vector>
using namespace std;

#include "person.h"

class Client : public Person
{
private:
  double balance;
  vector<Client> clients;

public:
  Client(int id, const string &name, const string &password, double balance);

  //* Setters
  void setBalance(double balance);

  //* Getters
  double getBalance() const;

  //* Deposit, Withdraw, Transfer, and Display methods
  void deposit(double amount);
  void withdraw(double amount);
  void transferTo(double amount, Client &recipient);
  void displayMyInfo() const;
  void updatePassword();
};