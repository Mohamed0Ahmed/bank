#pragma once
#include <string>
using namespace std;
#include <vector>

#include "admin.h"

class AdminManager
{
public:
  static void printAdminMenu();
  static Admin *login(int id, string password);
  static void adminOptions(Admin *admin);
};