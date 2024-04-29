#include <iostream>
using namespace std;

#include "person.h"
#include "validation.h"

Person::Person(int id, const string &name, const string &password)
    : id(id), name(name), password(password) {}

int Person::getId() const
{
  return id;
}

void Person::setId(int id)
{
  this->id = id;
}
double Person::getBalance() const
{
  return balance;
}

const string &Person::getName() const
{

  return name;
}

void Person::setName(const string &name)
{

  string newName = name;
  //* Check
  if (!Validation::checkName(newName))
  {
    cout << "Invalid name . Name must be atleast 8 characters , \n";
  }

  //* continue asking
  while (!Validation::checkName(newName))
  {
    cout << "Enter New Name : ";
    getline(cin, newName);
  }
  this->name = newName;
}

const string &Person::getPassword() const
{

  return password;
}

void Person::setPassword(const string &password)
{
  string newPassword = password;
  //* Check
  if (!Validation::checkPassword(newPassword))
  {
    cout << "Password must be atleast 8 characters,\n";
  }

  //* continue asking
  while (!Validation::checkPassword(newPassword))
  {
    cout << "Enter New Password : ";
  }
  this->password = newPassword;
}