#include "adminManager.h"
#include "fileHelper.h"
#include "fileManager.h"
#include "employee.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

FileManager fileManager;

void AdminManager::printAdminMenu()
{
  cout << "\n==========\n";
  cout << "Admin Menu:\n\n";
  cout << "1.  Add new employee" << endl;
  cout << "2.  Add new client" << endl;
  cout << "3.  List all employees" << endl;
  cout << "4.  Search for an employee" << endl;
  cout << "5.  Edit employee information" << endl;
  cout << "6.  List all clients" << endl;
  cout << "7.  Search for a client" << endl;
  cout << "8.  Edit client information" << endl;
  cout << "9.  Display admin details" << endl;
  cout << "10. Remove all clients" << endl;
  cout << "11. Remove all employees" << endl;
  cout << "12. Remove all admins" << endl;
  cout << "13. Logout" << endl;
  cout << "Enter your choice: ";
}

Admin *AdminManager::login(int id, string password)
{
  vector<Admin> admins = FilesHelper::getAdmins();

  for (auto &admin : admins)
  {
    if (admin.getId() == id && admin.getPassword() == password)
    {
      Admin *loggedInAdmin = new Admin(admin);
      return loggedInAdmin;
    }
  }
  cout << "Invalid id or password .Please try again later\n\n";

  return nullptr;
}

void AdminManager::adminOptions(Admin *admin)
{
  if (admin == nullptr)
  {
    cout << "Login failed. Invalid ID or password." << endl;
    return;
  }

  cout << "\nWelcome Mr. " << admin->getName() << endl;

  while (true)
  {
    printAdminMenu();
    string choiceStr;
    cout << "Enter your choice: ";
    cin >> choiceStr;

    try
    {
      int choice = stoi(choiceStr);
      switch (choice)
      {
      case 1:
      {
        string name, password;
        double salary;
        Employee newEmployee(1, name, password, salary);
        cout << "Enter new Employee information:" << endl;

        cout << "Name: ";
        cin >> name;
        newEmployee.setName(name);

        cout << "Password: ";
        cin >> password;
        newEmployee.setPassword(password);

        cout << "Salary: ";
        cin >> salary;
        newEmployee.setSalary(salary);

        admin->addEmployee(newEmployee);
      }
      break;
      case 2:
      {
        string name, password;
        double balance;
        cout << "Enter new client information:" << endl;
        Client newClient(1, name, password, balance);

        cout << "Name: ";
        cin >> name;
        newClient.setName(name);

        cout << "Password: ";
        cin >> password;
        newClient.setPassword(password);

        cout << "Balance: ";
        cin >> balance;
        newClient.setBalance(balance);

        admin->addClient(newClient);
      }
      break;
      case 3:
        admin->displayAllEmployees();
        break;
      case 4:
      {
        int id;
        cout << "Enter employee ID to Search : ";
        cin >> id;
        Employee *emp = admin->searchEmployeeById(id);
        if (emp)
        {
          emp->displayEmployeeDetails();
        }
        break;
      }
      case 5:
      {

        int id;
        cout << "Enter Employee id to edit: ";
        cin >> id;
        Employee *emp = admin->searchEmployeeById(id);
        if (emp)
          admin->editEmployeeInfo(*emp);
        break;
      }
      case 6:
        admin->displayAllClients();
        break;
      case 7:
      {
        int id;
        cout << "Enter client ID to Search : ";
        cin >> id;
        Client *cl = admin->searchClientById(id);
        if (cl)
        {
          cl->displayMyInfo();
        }

        break;
      }
      case 8:
      {
        int id;
        cout << "Enter Client id to edit: ";
        cin >> id;
        Client *cl = admin->searchClientById(id);
        if (cl)
          admin->editClientInfo(*cl);
        break;
      }
      case 9:
        admin->displayAdminDetails();
        break;
      case 10:
        fileManager.removeAllClients();
        cout << "\nAll clients removed.\n\n";
        break;
      case 11:
        fileManager.removeAllEmployees();
        cout << "\nAll employees removed.\n\n";
        break;
      case 12:
        fileManager.removeAllAdmins();
        cout << "\nAll admins removed.\n\n";
        break;
      case 13:
        return;
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
