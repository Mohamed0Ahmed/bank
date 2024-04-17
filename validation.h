#include <string>
#include <iostream>
#include <cctype>
using namespace std;

class Validation
{
public:
  static bool checkName(const string &name);
  static bool checkPassword(const string &password);
  static bool checkBalance(double balance);
  static bool checkSalary(double salary);
};