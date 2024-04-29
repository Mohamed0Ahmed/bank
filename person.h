#pragma once
#include <string>
using namespace std;


class Person
{
protected:
  int id;
  string name;
  string password;
  double balance;

public:
  Person(int id, const string &name, const string &password);
  int getId() const;
  void setId(int id);
  const string &getName() const;
  void setName(const string &name);
  const string &getPassword() const;
  void setPassword(const string &password);
  double getBalance() const;
};