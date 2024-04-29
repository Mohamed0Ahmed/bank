#include "employeeManager.h"
#include "fileHelper.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//* Print employee menu
void EmployeeManager::printEmployeeMenu()
{
  cout << "\n==========\n";
  cout << "Employee Menu:\n\n";
  cout << "1. Add new client" << endl;
  cout << "2. List all clients" << endl;
  cout << "3. Search for a client" << endl;
  cout << "4. Edit client information" << endl;
  cout << "5. Update password" << endl;
  cout << "6. Display MY Details" << endl;
  cout << "7. Logout" << endl;
  cout << "Enter your choice: ";
}

//* Add new client
void EmployeeManager::newClient(Employee *employee)
{
  string name, password;
  double balance;
  int id = 1;

  Client newClient(id, name, password, balance);
  cout << "Enter new client information:" << endl;

  cout << "Name: ";
  cin >> name;
  newClient.setName(name);

  cout << "Password: ";
  cin >> password;
  newClient.setPassword(password);

  cout << "Balance: ";
  cin >> balance;
  newClient.setBalance(balance);

  employee->addClient(newClient);
}

// *List all clients
void EmployeeManager::listAllClients(Employee *employee)
{
  employee->displayAllClients();
}

//* Search for a client
void EmployeeManager::searchForClient(Employee *employee)
{
  int id;
  cout << "Enter client id to search: ";
  cin >> id;
  Client *cl = employee->searchClientById(id);
  if (cl)
  {
    cl->displayMyInfo();
  }
}

//* Edit client information
void EmployeeManager::editClientInfo(Employee *employee)
{
  int id;
  cout << "Enter client id to edit: ";
  cin >> id;
  Client *client = employee->searchClientById(id);
  if (client)
    employee->editClientInfo(*client);
}

//* Update password
void EmployeeManager::updatePassword(Employee *employee)
{
  string newPassword;
  cout << "======\n";
  cout << "Enter new password: ";
  cin >> newPassword;
  employee->setPassword(newPassword);
}

//* Display my details
void EmployeeManager::displayMyDetails(Employee *employee)
{
  employee->displayEmployeeDetails();
}

//* Login
Employee *EmployeeManager::login(int id, string password)
{
  vector<Employee> employees = FilesHelper::getEmployees();

  for (auto &employee : employees)
  {
    if (employee.getId() == id && employee.getPassword() == password)
    {
      Employee *loggedInEmployee = new Employee(employee);
      return loggedInEmployee;
    }
  }
  cout << "Invalid id or password .Please try again later\n\n";
  return nullptr;
}

//* Employee options
bool EmployeeManager::employeeOptions(Employee *employee)
{
  if (employee == nullptr)
  {
    cout << "Login failed. Invalid ID or password." << endl;
    return false;
  }
  cout << "\nWelcome Mr. " << employee->getName() << endl;

  while (true)
  {
    printEmployeeMenu();
    string choiceStr;
    cout << "Enter your choice: ";
    cin >> choiceStr;

    try
    {
      int choice = stoi(choiceStr);
      switch (choice)
      {
      case 1:
        newClient(employee);
        break;
      case 2:
        listAllClients(employee);
        break;
      case 3:
      {
        searchForClient(employee);
        break;
      }
      case 4:
        editClientInfo(employee);
        break;
      case 5:
        updatePassword(employee);
        break;
      case 6:
        displayMyDetails(employee);
        break;
      case 7:
        return false;
      default:
        cout << "Invalid choice. Please try again." << endl;
      }
    }
    catch (const invalid_argument &)
    {
      cout << "Invalid choice. Please try again." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
}
