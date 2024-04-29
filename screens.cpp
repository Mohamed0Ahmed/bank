#include "Screens.h"
#include <iostream>
using namespace std;

#include "clientManager.h"
#include "employeeManager.h"
#include "adminManager.h"
#include "fileHelper.h"
#include "fileManager.h"

void Screens::bankName()
{
  cout << "           Egypt Bank\n\n";
}

void Screens::welcome()
{
  cout << "Welcome to Egypt Bank. Please login to continue." << endl;
}

void Screens::loginOptions()
{
  cout << "Login Options:" << endl;
  cout << "1. Login as Client" << endl;
  cout << "2. Login as Employee" << endl;
  cout << "3. Login as Admin" << endl;
  cout << "4. Exit" << endl;
}

int Screens::loginAs()
{
  int choice;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

void Screens::invalid(int c)
{
  cout << "Invalid choice: " << c << endl;
}

void Screens::logout()
{
  cout << "======\n\n";
  cout << "Logged out successfully.\n\n";
}

void Screens::loginScreen(int c)
{
  switch (c)
  {
  case 1:
  {
    int id;
    string password;
    cout << "\nEnter id to login : \n";
    cin >> id;
    cout << "\nEnter Password : \n";
    cin >> password;
    Client *cl = ClientManager::login(id, password);
    if (cl)
    {
      ClientManager::clientOptions(cl);
      logout();
    }

    break;
  }

  case 2:
  {
    int id;
    string password;
    cout << "\nEnter id to login : \n";
    cin >> id;
    cout << "\nEnter Password : \n";
    cin >> password;
    Employee *emp = EmployeeManager::login(id, password);
    if (emp)
    {
      EmployeeManager::employeeOptions(emp);
      logout();
    }

    break;
  }
  break;
  case 3:

  {
    int id;
    string password;
    cout << "\nEnter id to login : \n";
    cin >> id;
    cout << "\nEnter Password : \n";
    cin >> password;
    Admin *ad = AdminManager::login(id, password);
    if (ad)
    {
      AdminManager::adminOptions(ad);
      logout();
    }

    break;
  }

  break;
  default:
    invalid(c);
    break;
  }
}

void Screens::runApp()
{
  if (FilesHelper::getAdmins().empty())
  {
    Admin *defaultAdmin = Admin::getInstance();
    FileManager file ;
    file.addAdmin(*defaultAdmin);
  }

  bankName();
  welcome();
  while (true)
  {
    loginOptions();
    int choice = loginAs();
    if (choice == 4)
    {
      cout << "\n\nGoodBye ....";
      break;
    }
    else if (choice >= 1 && choice <= 3)
    {
      loginScreen(choice);
    }
    else
    {
      invalid(choice);
    }
  }
}
