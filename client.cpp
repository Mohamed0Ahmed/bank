#include "client.h"
#include "validation.h"
#include "fileHelper.h"
#include "clientManager.h"
#include <iostream>
using namespace std;

Client::Client(int id, const string &name, const string &password, double balance)
    : Person(id, name, password), balance(balance) {}

//* set balance
void Client::setBalance(double balance)
{
  double newBalance = balance;
  //* Check
  if (!Validation::checkBalance(newBalance))
  {
    cout << "Balance Must be over 1500,\n";
  }

  //* continue asking
  while (!Validation::checkBalance(newBalance))
  {
    cout << "Enter New balance : ";
    cin >> newBalance;
  }
  this->balance = newBalance;
}

double Client::getBalance() const
{
  return balance;
}

//* deposit
void Client::deposit(double amount)
{

  ClientManager::deposit(*this, amount);
}

//* withdraw
void Client::withdraw(double amount)
{
  cout << "=============== \n\n";

  ClientManager::withdraw(*this, amount);
}

//* transfer to
void Client::transferTo(double amount, Client &recipient)
{

  ClientManager::transferTo(*this, amount, recipient);
}

//* display my info
void Client::displayMyInfo() const
{
  vector<Client> clients = FilesHelper::getClients();
  int clientId = getId();
  bool found = false;

  for (const auto &client : clients)
  {
    if (client.getId() == clientId)
    {
      found = true;
      cout << "=============== \n\n";
      cout << "Client Details : \n\n";
      cout << "Client ID : " << client.getId() << ",    Name : " << client.getName() << ",    Balance : " << client.getBalance() << ",    Password : " << client.getPassword() << endl;
      break; 
    }
  }
}

//* update password
void Client::updatePassword()
{
  ClientManager::updatePassword(this);
};
