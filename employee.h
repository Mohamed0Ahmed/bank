#pragma once
#include <string>

#include "person.h"
#include "client.h"
#include <vector>

using namespace std;

class Employee : public Person
{
private:
  double salary;
  vector<Client> clients;

public:
  Employee(int id, const string &name, const string &password, double salary);

  double getSalary() const;
  void setSalary(double salary);
  void DisplayEmployeeDetails();
  bool login(int id, const string &password);
  void addClient(vector<Client> &allClients);
  Client *searchClient(const vector<Client> &clients);
  void displayAllClients(const vector<Client> &clients) const;
  Client *editClientInfo( vector<Client> &clients);
};