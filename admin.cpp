#include "admin.h"
#include "fileHelper.h"
#include "fileManager.h"
#include <iostream>

#include <limits>
#include <cstdlib>

Admin *Admin::instance = nullptr;

Admin::Admin(int id, const string &name, const string &password, double salary)
    : Employee(id, name, password, salary) {}

Admin *Admin::getInstance()
{
  if (!instance)
  {
    //* default instance for admin
    instance = new Admin(1, "Admin", "admin123", 15000);
  }
  return instance;
}

void Admin::destroyInstance()
{
  if (instance)
  {
    delete instance;
    instance = nullptr;
  }
}

//* show admin information
void Admin::displayAdminDetails() const
{

  cout << "========\n\n";
  cout << "ID: " << getId() << endl;
  cout << "Name: " << getName() << endl;
  cout << "Password: " << getPassword() << endl;
  cout << "Salary: " << getSalary() << endl;
  cout << "========\n\n";
}

//* add employee
void Admin::addEmployee(const Employee &newEmployee)
{
  FileManager fileManager;
  fileManager.addEmployee(newEmployee);
}

//* search for employee
Employee *Admin::searchEmployeeById(int employeeId)
{

  FilesHelper fileHelper;
  vector<Employee> employees = fileHelper.getEmployees();
  for (auto &employee : employees)
  {
    if (employee.getId() == employeeId)
    {
      cout << "==========\n\n";
      cout << "Employee is found.\n\n";
      return &employee;
    }
  }
  cout << "==========\n\n";
  cout << "Employee not found." << endl;
  return nullptr;
}

//* edit employee information

void Admin::editEmployeeInfo(Employee &employee)
{
  employees = FilesHelper::getEmployees();

  while (true)
  {
    cout << "Editing employee information:" << endl;
    cout << "1. Edit Name" << endl;
    cout << "2. Edit Password" << endl;
    cout << "3. Edit Salary" << endl;
    cout << "4. Done Editing" << endl;
    cout << "Enter your choice: ";

    string choiceStr;
    cin >> choiceStr;

    try
    {
      int choice = stoi(choiceStr);
      switch (choice)
      {
      case 1:
      {
        string newName;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, newName);
        employee.setName(newName);
        break;
      }
      case 2:
      {
        string newPassword;
        cout << "Enter new password: ";
        cin.ignore();
        getline(cin, newPassword);
        employee.setPassword(newPassword);
        break;
      }
      case 3:
      {
        double newSalary;
        cout << "Enter new salary: ";
        cin >> newSalary;
        employee.setSalary(newSalary);
        break;
      }
      case 4:
        for (auto &e : employees)
        {
          if (e.getId() == employee.getId())
          {
            e = employee;
            break;
          }
        }
        FilesHelper::updateEmployeeFile(employees);
        cout << "Employee information updated successfully." << endl;
        return;
      default:
        cout << "\nInvalid choice. Please try again.\n\n";
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

//* Display All Employees
void Admin::displayAllEmployees() const
{
  cout << "\n ========== \n";
  vector<Employee> employees = FilesHelper::getEmployees();

  cout << "List of Employees: \n\n";
  for (const auto &employee : employees)
  {
    cout << "ID: " << employee.getId() << "     Name: " << employee.getName() << "    Salary: " << employee.getSalary() << "    Password: " << employee.getPassword() << "\n";
  }
}
