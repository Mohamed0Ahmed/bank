#pragma once

using namespace std;

#include <string>
#include <vector>
#include "client.h"
#include "employee.h"
#include "admin.h"

class FilesHelper
{

public:
  static void saveLast(const string &fileName, int id);
  static int getLast(const string &fileName);
  static void saveClient(const string &fileName, const string &lastIdFile, const Client &c);
  static void saveEmployee(const string &fileName, const string &lastIdFile, const Employee &e);
  static vector<Client> getClients();
  static vector<Employee> getEmployees();
  static vector<Admin> getAdmins();
  static void clearFile(const string &fileName, const string &lastIdFile);

  static void updateClientFile(vector<Client> clients);
  static void updateEmployeeFile(vector<Employee> employees);
};
