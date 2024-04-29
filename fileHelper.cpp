#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#include "fileHelper.h"
#include "parser.h"

//* save client
void FilesHelper::saveClient(const string &fileName, const string &lastIdFile, const Client &c)
{
  ofstream file("Clients.txt", ios::app);
  if (file.is_open())
  {
    int id = getLast(lastIdFile) + 1;
    file << id << "," << c.getName() << "," << c.getPassword() << "," << c.getBalance() << "\n";
    saveLast(lastIdFile, id);
    file.close();
    cout << "=======\n\n";
    cout << "Client saved." << endl;
    cout << "Account id is : " << id << endl;
  }
  else
  {
    cerr << "Error: Unable to open Clients.txt for writing." << endl;
  }
}

//* save employee
void FilesHelper::saveEmployee(const string &fileName, const string &lastIdFile, const Employee &e)
{
  ofstream file(fileName, ios::app);
  if (file.is_open())
  {
    int id = getLast(lastIdFile) + 1;
    file << id << "," << e.getName() << "," << e.getPassword() << "," << e.getSalary() << "\n";
    saveLast(lastIdFile, id);
    file.close();
    cout << "=======\n\n";
    cout << "Employee saved." << endl;
    cout << "Employee id is : " << id << endl;
  }
  else
  {
    cerr << "Error: Unable to open " << fileName << " for writing." << endl;
  }
}

//* get clients
vector<Client> FilesHelper::getClients()
{
  vector<Client> clients;
  ifstream file("Clients.txt");
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      Client client = Parser::parseToClient(line);
      clients.push_back(client);
    }
    file.close();
  }
  else
  {
    cerr << "Error: Unable to open Clients.txt for reading." << endl;
  }

  return clients;
}

//* get employees
vector<Employee> FilesHelper::getEmployees()
{
  vector<Employee> employees;
  ifstream file("Employees.txt");
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      Employee employee = Parser::parseToEmployee(line);
      employees.push_back(employee);
    }
    file.close();
  }
  else
  {
    cerr << "Error: Unable to open Employees.txt for reading." << endl;
  }

  return employees;
}

//* get admins
vector<Admin> FilesHelper::getAdmins()
{
  vector<Admin> admins;

  ifstream file("Admins.txt");
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      Admin admin = Parser::parseToAdmin(line);
      admins.push_back(admin);
    }
    file.close();
  }
  else
  {
    cerr << "Error: Unable to open Admins.txt for reading." << endl;
  }

  return admins;
}

void FilesHelper::clearFile(const string &fileName, const string &lastIdFile)
{
  ofstream file(fileName);
  if (file.is_open())
  {
    file.close();
    saveLast(lastIdFile, 0);
  }
  else
  {
    cerr << "Error: Unable to open " << fileName << " for writing." << endl;
  }
}

void FilesHelper::saveLast(const string &fileName, int id)
{
  ofstream file(fileName);
  if (file.is_open())
  {
    file << id;
    file.close();
  }
  else
  {
    cerr << "Error: Unable to open file " << fileName << " for writing." << endl;
  }
}

int FilesHelper::getLast(const string &fileName)
{
  int id = 0;
  ifstream file(fileName);
  if (file.is_open())
  {
    file >> id;
    file.close();
  }
  else
  {
    cerr << "Error: Unable to open file " << fileName << " for reading." << endl;
  }
  return id;
}

//* update Clients after edit
void FilesHelper::updateClientFile(vector<Client> clients)
{

  ofstream file("Clients.txt");
  if (file.is_open())
  {
    for (const Client &client : clients)
    {
      file << client.getId() << "," << client.getName() << "," << client.getPassword() << "," << client.getBalance() << "\n";
    }
    file.close();
  }
  else
  {
    cerr << "Error: Unable to open Clients.txt for writing." << endl;
  }
}
//* update Employees after edit
void FilesHelper::updateEmployeeFile(vector<Employee> employees)
{

  ofstream file("Employees.txt");
  if (file.is_open())
  {
    for (const Employee &employee : employees)
    {
      file << employee.getId() << "," << employee.getName() << "," << employee.getPassword() << "," << employee.getSalary() << "\n";
    }
    file.close();
  }
  else
  {
    cerr << "Error: Unable to open Employees.txt for writing." << endl;
  }
}
