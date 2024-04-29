#include "parser.h"
#include "admin.h"
#include <sstream>
using namespace std;

vector<string> Parser::split(const string &line)
{
  vector<string> tokens;
  istringstream iss(line);
  string token;
  while (getline(iss, token, ','))
  {
    tokens.push_back(token);
  }
  return tokens;
}

Client Parser::parseToClient(const string &line)
{
  vector<string> tokens = split(line);
  int id = stoi(tokens[0]);
  string name = tokens[1];
  string password = tokens[2];
  double balance = stod(tokens[3]);
  return Client(id, name, password, balance);
}

Employee Parser::parseToEmployee(const string &line)
{
  vector<string> tokens = split(line);
  int id = stoi(tokens[0]);
  string name = tokens[1];
  string password = tokens[2];
  double salary = stod(tokens[3]);
  return Employee(id, name, password, salary);
}

Admin Parser::parseToAdmin(const string &line)
{
  vector<string> tokens = split(line);
  int id = stoi(tokens[0]);
  string name = tokens[1];
  string password = tokens[2];
  double salary = stod(tokens[3]);

  //* Get the Admin instance 
  Admin *adminPtr = Admin::getInstance();
  if (adminPtr != nullptr)
  {
    //* Set the properties of the Admin instance
    adminPtr->setId(id);
    adminPtr->setName(name);
    adminPtr->setPassword(password);
    adminPtr->setSalary(salary);
  }
  else
  {
    throw runtime_error("Failed to get Admin instance");
  }

  return *adminPtr;
}
