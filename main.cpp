#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#include "admin.h"
#include "client.h"
#include "screens.h"

int main()
{
  char choice;
  string password;
  string name;
  int id;
  double salary;
  double amount;
  double balance;
  bool close = false;
  bool transClient = false;

  //** Instances of classes
  Screen screen;
  vector<Client> clients;
  vector<Employee> employees;
  vector<Admin> admins;

  //** Create default admin and employee
  employees.emplace_back(2, "Employee", "employee123", 7000);
  admins.emplace_back(1, "Admin", "admin123", 10000, employees);

  //** Welcome message
  screen.WelcomePage();

  do
  {
    //** Main menu
    screen.mainMenu();
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 'c':
    case 'C': //** Client menu
      cout << "Do You have An Account (Y/N)?" << endl;
      cin >> choice;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      switch (choice)
      {
      case 'y':
      case 'Y':
      {
        cout << "Login First" << endl;
        cout << "Enter Your ID :";
        cin >> id;
        cout << "Enter Your Password :";
        cin >> password;

        //** Find the client with the matching ID
        bool foundClient = false;
        for (auto &client : clients)
        {
          if (client.login(id, password))
          {
            cout << "Login Successful\n\n";
            foundClient = true;

            //** Client menu loop
            cout << "Welcome Mr." << client.getName();
            do
            {
              screen.clientMenu();
              cin >> choice;
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              switch (choice)
              {
              case '1': //** Check Balance
                client.checkBalance();
                break;
              case '2': //** Deposit
                cout << "Enter amount to deposit: ";
                cin >> amount;
                client.deposit(amount);
                break;
              case '3': //** Withdraw
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                client.withdraw(amount);
                break;
              case '4': //** Transfer
                cout << "Enter amount to transfer: ";
                cin >> amount;
                cout << "Enter ID of the client to transfer to: ";
                cin >> id;
                for (auto &cli : clients)
                {
                  if (cli.getId() == id)
                  {
                    cout << "\n\n";
                    client.transferTo(cli, amount); //* Assuming transfer to the first client
                    transClient = true;
                    break;
                  }
                }

                //* If no client
                if (!transClient)
                {
                  cout << "\nNo client found \n";
                }

                break;
              case '5': //** Display Client Info
                client.DisplayClientInfo();
                break;
              case '6': //** Return to main menu
                break;
              default:
                cout << "Invalid choice. Please try again." << endl;
                break;
              }
            } while (choice != '6');

            break;
          }
        }

        if (!foundClient)
        {
          cout << "\n\nLogin Failed... Back To Main \n\n";
        }
      }
      break;

      case 'n':
      case 'N': //** Create new account
        cout << "Create New Account ... \n\n";
        employees[0].addClient(clients);
        break;
      }
      break;

    case 'A':
    case 'a': //** Admin menu
    {
      cout << "Note : Admin id is '1' and admin pass is 'admin123' \n\n";
      cout << "You have To login First" << endl;
      cout << "Enter Your ID :";
      cin >> id;
      cout << "Enter Your Password :";
      cin >> password;

      if (admins[0].login(id, password))
      {
        cout << "\nLogin Successful\n\n";

        //** Admin menu loop
        do
        {
          screen.adminMenu();
          cin >> choice;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          switch (choice)
          {
          case '1': //** Add Employee
            admins[0].addEmployee(employees);
            break;
          case '2': //** Search Employee
            cout << "Enter employee id to search for..." << endl;
            cin >> id;
            admins[0].searchEmployee(id, employees);
            break;
          case '3': //** Edit Employee Info
            cout << "Enter employee id to edit..." << endl;
            cin >> id;
            admins[0].editEmployeeInfo(id, employees);
            break;
          case '4': //** Display all Employees
            admins[0].displayAllEmployees(employees);
            break;
          case '5': //** Display all Clients
            admins[0].displayAllClients(clients);
            break;
          case '6': //** Add Client
            admins[0].addClient(clients);
            break;
          case '7': //** Return to main menu
            break;
          default:
            cout << "Invalid choice. Please try again." << endl;
            break;
          }
        } while (choice != '7');
      }
      else
      {
        cout << "\n\n\nLogin Failed... Back To Main \n\n";
      }
    }
    break;

    case 'E':
    case 'e': //** Employee menu
    {
      cout << "Note : Admin id is '2' and admin pass is 'employee123' \n\n";

      cout << "You have To login First" << endl;
      cout << "Enter Your ID :";
      cin >> id;
      cout << "Enter Your Password :";
      cin >> password;

      //** Find the employee with the matching ID
      bool foundEmployee = false;
      for (auto &employee : employees)
      {
        if (employee.login(id, password))
        {
          cout << "Login Successful\n\n";
          foundEmployee = true;

          //** Employee menu loop
          do
          {
            screen.employeeMenu();
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (choice)
            {
            case '1': //* Add Client
              employee.addClient(clients);
              break;
            case '2': //* Search Client
              employee.searchClient(clients);
              break;
            case '3': //* Edit Client Info
              employee.editClientInfo(clients);
              break;
            case '4': //* Display Employee Details
              cout << "My details...\n\n";
              employee.DisplayEmployeeDetails();
              break;
            case '5': //* Display all Clients
              employee.displayAllClients(clients);
              break;
            case '6': //* Return to main menu
              break;
            default:
              cout << "Invalid choice. Please try again." << endl;
              break;
            }

          } while (choice != '6');

          break;
        }
      }

      if (!foundEmployee)
      {
        cout << "\n\nLogin Failed... Back To Main \n\n";
      }
    }
    break;

    case 'x':
    case 'X': //* Exit
      close = true;
      cout << "Goodbye..." << endl;
      break;

    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
  } while (!close);

  return 0;
}
