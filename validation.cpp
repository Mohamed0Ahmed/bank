#include <iostream>
using namespace std ;

#include "validation.h"
#include <regex>
#include <string>

bool Validation::checkName(const string &name)
{
  return regex_match(name, regex("^[a-zA-Z ]{5,20}$"));
}

bool Validation::checkPassword(const string &password)
{
  return (password.length() >= 8 && password.length() <= 20);
}

bool Validation::checkBalance(double balance)
{
  return (balance >= 1500);
}

bool Validation::checkSalary(double salary)
{
  return (salary >= 5000);
}