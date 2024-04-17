
#pragma once
#include <iostream>
#include <vector>

using namespace std;

#include "admin.h"
#include "client.h"

class Screen
{
public:
  // //* varialbes
  int choice;
  string password;
  string name;
  int id;
  double salary;
  double balance;

  vector<Client> clients;
  vector<Employee> employees;
  vector<Admin> admins;

  //* methods
  void WelcomePage();
  void mainMenu();
  void adminMenu();
  void clientMenu();
  void employeeMenu();
};
