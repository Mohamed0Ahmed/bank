
#pragma once
#include <string>
using namespace std;
#include <vector>

#include "person.h"
#include "client.h"

class Employee : public Person
{
private:
  double salary;
  vector<Client> clients;

public:
  Employee(int id, const string &name, const string &password, double salary);

  double getSalary() const;
  void setSalary(double salary);
  void displayEmployeeDetails() const;
  void login(int id, const string &password);
  void addClient(const Client &newClient);
  Client *searchClientById(int clientId);
  void displayAllClients() const;
  void editClientInfo(Client &client);
};
