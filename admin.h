#pragma once
#include <string>
#include <vector>

using namespace std;

#include "employee.h"

class Admin : public Employee
{
private:
  vector<Employee> &employees;

public:
  Admin(int id, const string &name, const string &password, double salary, vector<Employee> &allEmployees);
  void addEmployee(vector<Employee> &allEmployees);
  Employee *searchEmployee(int employeeId, vector<Employee> &employees);
  Employee *editEmployeeInfo(int employeeId, vector<Employee> &employees);
  void displayAllEmployees(const vector<Employee> &employees);
};