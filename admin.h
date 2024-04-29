#pragma once
#include <string>
using namespace std;

#include <vector>

#include "employee.h"

class Admin : public Employee
{
private:
  static Admin *instance;
  vector<Employee> employees;

public:
  Admin(int id, const string &name, const string &password, double salary);
  static Admin *getInstance();
  void displayAdminDetails() const;
  void addEmployee(const Employee &newEmployee);
  Employee *searchEmployeeById(int employeeId);
  void editEmployeeInfo(Employee &employee);
  void displayAllEmployees() const;
  static void destroyInstance();
};