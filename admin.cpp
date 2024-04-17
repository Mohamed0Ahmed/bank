#include <iostream>
#include <limits>

using namespace std;

#include "admin.h"
#include "validation.h"
#include "employee.h"

Admin::Admin(int id, const string &name, const string &password, double salary, vector<Employee> &allEmployees)
    : Employee(id, name, password, salary), employees(allEmployees) {}


//* add emp
void Admin::addEmployee(vector<Employee> &allEmployees)
{

  double salary;

  cout << "========== Adding employee ==========\n\n";

  //* Ask for employee ID
  do
  {
    cout << "Enter employee ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //* Check if the employee ID already exists
    bool idExists = false;
    for (const auto &employee : allEmployees)
    {
      if (employee.getId() == id)
      {
        idExists = true;
        cout << "Employee with ID " << id << " already exists. Please enter another ID." << endl;
        break;
      }
    }
    if (!idExists)
      break; //* Exit
  } while (true);

  cout << "Enter employee name: ";
  cin.ignore(); //* Ignore the newline character left in the input buffer
  setName(name);

  cout << "Enter employee password: ";
  setPassword(password);

  //* Ask for salary until a valid one is provided
  do
  {
    cout << "Enter new salary: ";
    cin >> salary;

    if (!Validation::checkSalary(salary))
    {
      cout << "Salary must be over 5000." << endl;
    }
  } while (!Validation::checkSalary(salary));

  //* Create a new employee object and add it to the admin's list of employees
  employees.emplace_back(id, name, password, salary);

  cout << "\nEmployee added.\n\n";
}

//* search for emp 
Employee *Admin::searchEmployee(int employeeId, vector<Employee> &employees)
{
  for (auto &employee : employees)
  {
    if (employee.getId() == employeeId)
    {
      cout << "\nEmployee found:\n" << endl;
      employee.DisplayEmployeeDetails();
      return &employee;
    }
  }
  cout << "\nEmployee with ID " << employeeId << " not found." << endl;
  return nullptr;
}

//* Edit Employee
Employee *Admin::editEmployeeInfo(int employeeId ,vector<Employee> &employees)
{

  for (auto &employee : employees)
  {
    if (employee.getId() == employeeId)
    {
      cout << "\nEmployee found:" << endl;

      cout << "Editing employee information.\n" << endl;

      cout << "Enter new name: ";
      string newName;
      cin.ignore();
      employee.setName(newName);

      cout << "Enter new password: ";
      string newPassword;
      employee.setPassword(newPassword);

      double newSalary;
      cout << "Enter new salary: ";

      employee.setSalary(newSalary);

      cout << "\nEmployee information updated successfully.\n" << endl;

      return &employee;
    }
  }
  cout << "\nEmployee with ID " << employeeId << " not found.\n" << endl;
  return nullptr;
}

//* display all employees
void Admin::displayAllEmployees(const vector<Employee> &employees)
{
  int counter = 1;
  cout << "All Employees:\n\n";
  for (auto &employee : employees)
  {
    Employee tempEmployee = employee;
    cout << "Employee number : " << counter++ << "\n\n";
    tempEmployee.DisplayEmployeeDetails(); //* Display the details
    cout << endl;
  }
}