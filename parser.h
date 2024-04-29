#pragma once

using namespace std;

#include <vector>
#include <string>

#include "client.h"
#include "employee.h"
#include "admin.h"

class Parser
{
public:
  static vector<string> split(const string &line);
  static Client parseToClient(const string &line);
  static Employee parseToEmployee(const string &line);
  static Admin parseToAdmin(const string &line);
};
