#include <iostream>
#include <string>

using namespace std;

#include "client.h"
#include "validation.h"

Client::Client(int id, const string &name, const string &password, double balance)
    : Person(id, name, password), balance(balance) {}

double Client::getBalance() const
{
  return balance;
}

void Client::setBalance(double balance)
{

  cin >> this->balance;
  //* Check
  if (!Validation::checkBalance(this->balance))
  {
    cout << "Balance Must be over 1500,\n";
  }

  //* continue asking
  while (!Validation::checkBalance(this->balance))
  {
    cout << "Enter New balance : ";
    cin >> this->balance;
  }
}

//* ##### Deposit
void Client::deposit(double amount)
{
  balance += amount;
  cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
}

//* ##### Withdraw
void Client::withdraw(double amount)
{
  if (balance >= amount && Validation::checkBalance(balance - amount))
  {
    balance -= amount;
    cout << "Withdrawn $" << amount << ". New balance: $" << balance << endl;
  }
  else
  {
    cout << "Invaild ... Your Balance Must Be Over 1500 EGP " << endl;
  }
}

//* #### transfer to
void Client::transferTo(Client &recipient, double amount)
{
  if (balance >= amount && Validation::checkBalance(balance - amount))
  {
    balance -= amount;
    recipient.balance += amount;
    cout << "Transferred EGP " << amount << " to " << recipient.getName() << endl;
  }
  else
  {
    cout << "Invaild Transfer.. Your Balance Must Be Over 1500 EGP" << endl;
  }
}

//* ### check Balance
void Client::checkBalance()
{
  cout << "Current balance: EGP " << balance << endl;
}

//* display client information
void Client::DisplayClientInfo() const
{
  cout << "Client ID: " << getId() << endl;
  cout << "Name: " << getName() << endl;
  cout << "Balance: EGP " << getBalance() << endl;
  cout << "Password: " << getPassword() << endl;
}

//* login
bool Client::login(int id, const string &password)
{
  if (getId() == id && getPassword() == password)
  {
    return true;
  }
  else
    return false;
}
