#pragma once
using namespace std;

//* includes
#include "person.h"

class Client : public Person
{
private:
  double balance;
  int id;
  string name;

public:
  Client(int id, const string &name, const string &password, double balance);
  double getBalance() const;
  void setBalance(double balance);
  void deposit(double amount);
  void withdraw(double amount);
  void transferTo(Client &recipient, double amount);
  void checkBalance();
  void DisplayClientInfo() const;

  bool login(int id, const string &password);
};