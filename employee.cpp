#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "employee.h"
#include "client.h"
#include "validation.h"

Employee::Employee(int id, const string &name, const string &password, double salary)
    : Person(id, name, password), salary(salary) {}

//*#### setter and geeter for salary true
double Employee::getSalary() const
{
  return salary;
}

void Employee::setSalary(double salary)
{

  cin >> this->salary;
  //* Check
  if (!Validation::checkSalary(this->salary))
  {
    cout << "Salary must be over 5000 EGP ,\n";
  }

  //* continue asking
  while (!Validation::checkSalary(this->salary))
  {
    cout << "Enter New Salary : ";
    cin >> this->salary;
  }
}

//* Display employee information true
void Employee::DisplayEmployeeDetails()
{

  cout << "Employee ID: " << getId() << endl;
  cout << "Name: " << getName() << endl;
  cout << "Salary: EGP " << getSalary() << endl;
  cout << "Password: " << getPassword() << endl;
}

//* ### login for employee
bool Employee::login(int id, const string &password)
{
  if (getId() == id && getPassword() == password)
  {
    return true;
  }
  else
    return false;
}

//* ##  add client true
void Employee::addClient(vector<Client> &allClients)
{

  double balance;
  cout << "==========  Adding client ==========\n\n";

  //* Ask for client ID
  do
  {
    cout << "Enter client ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //* Check if the client ID already exists
    bool idExists = false;
    for (const auto &client : clients)
    {
      if (client.getId() == id)
      {
        idExists = true;
        cout << "Client with ID " << id << " already exists. Please enter another ID." << endl;
        break;
      }
    }
    if (!idExists)
      break; //* Exit
  } while (true);

  cout << "Enter client name: ";
  setName(name);
  cout << "Enter client password: ";
  setPassword(password);
  do
  {
    cout << "Enter new balance: ";
    cin >> balance;

    if (!Validation::checkBalance(balance))
    {
      cout << "Balance must be over 1500." << endl;
    }
  } while (!Validation::checkBalance(balance));

  clients.emplace_back(id, name, password, balance);
  allClients.push_back(clients.back());

  cout << "\nClient added.\n\n";
}

//* ##  search client true
Client *Employee::searchClient(const vector<Client> &clients)
{

  cout << "Enter Client ID To Search : ";
  cin >> id;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (auto &client : clients)
  {
    if (client.getId() == id)
    {
      cout << "Client found :\n\n";
      client.DisplayClientInfo();
      return nullptr;
    }
  }
  cout << "\n\nClient with ID " << id << " not found.\n\n";
  return nullptr;
}
//* display all clients
void Employee::displayAllClients(const vector<Client> &clients) const
{
  int counter = 1;
  if (clients.empty())
  {
    cout << "No clients yet." << endl;
    return;
  }

  cout << "\nAll Clients: \n\n";

  for (auto &client : clients)
  {
    cout << "Client number : " << counter++ << "\n\n";
    client.DisplayClientInfo();
    cout << "\n\n";
  }
}

//*  edit client
Client *Employee::editClientInfo(vector<Client> &clients)
{
  int clientId;
  cout << "Enter ID of client to edit info: ";
  cin >> clientId;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  //* Find the client
  for (auto &client : clients)
  {
    if (client.getId() == clientId)
    {
      cout << "Client found. Editing information for client with ID " << clientId << endl;
      //* Allow the user to edit client information
      cout << "Enter new name: ";
      cin.ignore();
      client.setName(name);

      cout << "Enter new password: ";
      client.setPassword(password);
      cout << "Enter new Balance: ";
      client.setBalance(balance);

      cout << "\n\nClient information updated successfully.\n"
           << endl;
      return &client;
    }
  }
  cout << "\nClient with ID " << clientId << " not found.\n\n";
  return nullptr;
}
