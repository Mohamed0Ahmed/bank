#include <iostream>
using namespace std;

#include "screens.h"
#include <string>

//* methods
void Screen::WelcomePage()
{
  cout << "======================================================= \n";
  cout << "\n                  Welcome to Our Bank!\n\n";
  cout << "======================================================= \n\n";
};
void Screen::mainMenu()
{
  cout << "1. If you are Client write    'c' " << endl;
  cout << "2. If you are Admin write     'a' " << endl;
  cout << "3. If you are Employee write  'e' " << endl;
  cout << "4. To close write             'x' " << endl;
  cout << "\n=========== \n";
};
void Screen::adminMenu()
{
  cout << "================================================= \n";
  cout << "1. Add an Employee" << endl;
  cout << "2. Search for Employee" << endl;
  cout << "3. Edit Employee info " << endl;
  cout << "4. Show all Employees " << endl;
  cout << "5. Show all clients " << endl;
  cout << "6. Add a client " << endl;
  cout << "7. Return to menu" << endl;
  cout << "Enter your choice: ";
  cout << "\n==============================================\n";
};

void Screen::employeeMenu()
{
  cout << "================================================= \n";
  cout << "1. Add a Client" << endl;
  cout << "2. Search for Client" << endl;
  cout << "3. Edit Client info " << endl;
  cout << "4. Display My Deatils " << endl;
  cout << "5. Show all clients " << endl;
  cout << "6. Return to menu" << endl;
  cout << "Enter your choice: ";
  cout << "\n==============================================\n";
};
void Screen::clientMenu()
{
  cout << "\n\n";
  cout << "================================================= \n";
  cout << "1. Check Your Balance" << endl;
  cout << "2. Deposit " << endl;
  cout << "3. Withdraw " << endl;
  cout << "4. Transfer To Another Client " << endl;
  cout << "5. Display My Account" << endl;
  cout << "6. Return to menu" << endl;
  cout << "Enter your choice: ";
  cout << "\n==============================================\n";
};
