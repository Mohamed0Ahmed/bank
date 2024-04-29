#include "employee.h"
#include "validation.h"
#include "fileHelper.h"
#include "fileManager.h"
#include <iostream>
using namespace std;

Employee::Employee(int id, const string &name, const string &password, double salary)
    : Person(id, name, password), salary(salary) {}

double Employee::getSalary() const
{
  return salary;
}

void Employee::setSalary(double salary)
{
  double newSalary = salary;
  //* Check
  if (!Validation::checkSalary(newSalary))
  {
    cout << "Salary must be over 5000 EGP ,\n";
  }

  //* continue asking
  while (!Validation::checkSalary(newSalary))
  {
    cout << "Enter New Salary : ";
  }
  this->salary = newSalary;
}

//* display information##############
void Employee::displayEmployeeDetails() const
{

  vector<Employee> employees = FilesHelper::getEmployees();
  int empId = getId();
  bool found = false;

  for (const auto &employee : employees)
  {
    if (employee.getId() == empId)
    {
      found = true;
      cout << "=============== \n\n";
      cout << "Employee Details : \n\n";
      cout << "Employee ID : " << employee.getId() << ",    Name : " << employee.getName() << ",    Salary : " << employee.getSalary() << ",    Password : " << employee.getPassword() << endl;
      break;
    }
  }
}

//* login
void Employee::login(int id, const string &password)
{
  if (getId() == id && getPassword() == password)
  {
    cout << "Login successful. Welcome, " << getName() << "!" << endl;
  }
  else
  {
    cout << "Login failed. Invalid ID or password." << endl;
  }
}

//* add client
void Employee::addClient(const Client &newClient)
{
  FileManager fileManager;

  fileManager.addClient(newClient);
}
//* search client
Client *Employee::searchClientById(int clientId)
{
  FilesHelper fileHelper;
  vector<Client> clients = fileHelper.getClients();
  for (auto &client : clients)
  {
    if (client.getId() == clientId)
    {
      cout << "\nClient is found.\n";
      return &client;
    }
  }
  cout << "==========\n\n";
  cout << "Client not found." << endl;
  return nullptr;
}

//*display all clients
void Employee::displayAllClients() const
{
  cout << "\n ========== \n\n";

  FilesHelper fileHelper;
  vector<Client> clients = fileHelper.getClients();

  cout << "List of Clients: \n\n";
  for (const auto &client : clients)
  {
    cout << "ID: " << client.getId() << "     Name: " << client.getName() << "    Balance: " << client.getBalance() << "    Password: " << client.getPassword() << "\n";
  }
}

//* edit client info
void Employee::editClientInfo(Client &client)
{
  clients = FilesHelper::getClients();
  while (true)
  {
    cout << "\n\n ========== \n\n";

    cout << "Editing client information:" << endl;
    cout << "1. Edit Name" << endl;
    cout << "2. Edit Password" << endl;
    cout << "3. Edit Balance" << endl;
    cout << "4. Done Editing" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      string newName;
      cout << "Enter new name: ";
      cin.ignore();
      getline(cin, newName);
      client.setName(newName);
      break;
    }
    case 2:
    {
      string newPassword;
      cout << "Enter new password: ";
      cin.ignore();
      getline(cin, newPassword);
      client.setPassword(newPassword);
      break;
    }
    case 3:
    {
      double newBalance;
      cout << "Enter new balance: ";
      cin >> newBalance;
      client.setBalance(newBalance);
      break;
    }
    case 4:
    {
      return;
    }
    default:
      cout << "Invalid choice. Please try again." << endl;
    }

    //* Ask if the user wants to continue editing
    cout << "Do you want to edit anything else? (y/n): ";
    char continueChoice;
    cin >> continueChoice;
    if (continueChoice != 'y' && continueChoice != 'Y')
    {
      break;
    }
  }
  for (auto &c : clients)
  {
    if (c.getId() == client.getId())
    {
      c = client;
      break;
    }
  }
  FilesHelper::updateClientFile(clients);
  cout << "Client information updated successfully." << endl;
}
