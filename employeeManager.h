#pragma once
#include <string>
using namespace std;
#include <vector>

#include "employee.h"
#include "client.h"

class EmployeeManager
{
public:
  static void printEmployeeMenu();
  static void newClient(Employee *employee);
  static void listAllClients(Employee *employee);
  static void searchForClient(Employee *employee);
  static void editClientInfo(Employee *employee);
  static Employee *login(int id, string password);
  static bool employeeOptions(Employee *employee);
  static void updatePassword(Employee *employee);
  static void displayMyDetails(Employee *employee);
};