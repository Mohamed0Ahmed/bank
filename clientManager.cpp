#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

#include "clientManager.h"
#include "filehelper.h"

//* print client menu
void ClientManager::printClientMenu()
{
  cout << "=============\n\n";

  cout << "Client Menu: \n\n";
  cout << "1. Deposit" << endl;
  cout << "2. Withdraw" << endl;
  cout << "3. Transfer" << endl;
  cout << "4. Update Password" << endl;
  cout << "5. Display My Details" << endl;
  cout << "6. Logout" << endl;
}

//* update password
void ClientManager::updatePassword(Person *person)
{
  string newPassword;
  cout << "Enter new password: ";
  cin >> newPassword;
  person->setPassword(newPassword);
  cout << "Password updated successfully." << endl;

  //* Check if the person is a client
  if (Client *client = static_cast<Client *>(person))
  {
    vector<Client> clients = FilesHelper::getClients();

    for (auto &c : clients)
    {
      if (c.getId() == client->getId())
      {
        c.setPassword(newPassword);
        break;
      }
    }

    FilesHelper::updateClientFile(clients);
  }
}

//* login
Client *ClientManager::login(int id, string password)
{
  vector<Client> clients = FilesHelper::getClients();

  for (auto &client : clients)
  {
    if (client.getId() == id && client.getPassword() == password)
    {
      Client *loggedInClient = new Client(client);
      return loggedInClient;
    }
  }
  cout << "Invalid id or password .Please try again later\n\n";
  return nullptr;
}

//* display options
bool ClientManager::clientOptions(Client *client)
{
  vector<Client> clients = FilesHelper::getClients();
  cout << "\nWelcome Mr. " << client->getName() << endl;

  if (client != nullptr)
  {
    while (true)
    {

      printClientMenu();
      string choiceStr;
      cout << "Enter your choice: ";
      cin >> choiceStr;

      try
      {
        int choice = stoi(choiceStr);
        switch (choice)
        {
        case 1:
          double depositAmount;
          cout << "Enter deposit amount: ";
          cin >> depositAmount;
          deposit(*client, depositAmount);
          break;
        case 2:
          double withdrawAmount;
          cout << "Enter withdrawal amount: ";
          cin >> withdrawAmount;
          withdraw(*client, withdrawAmount);
          break;
        case 3:
        {
          double transferAmount;
          int recipientId;
          cout << "Enter transfer amount: ";
          cin >> transferAmount;
          cout << "Enter recipient ID: ";
          cin >> recipientId;

          if (recipientId == client->getId())
          {
            cout << "\nYou cannot transfer to yourself. Transfer canceled." << endl;
            break;
          }

          bool recipientFound = false;
          for (auto &recipient : clients)
          {
            if (recipient.getId() == recipientId)
            {
              recipientFound = true;
              cout << "\nAre you sure you want to transfer to Mr. " << recipient.getName() << " (y/n) ";
              string confirmTransfer;
              cin >> confirmTransfer;

              if (confirmTransfer == "y" || confirmTransfer == "Y")
              {
                transferTo(*client, transferAmount, recipient);
              }
              else
              {
                cout << "\nTransfer canceled." << endl;
              }
              break;
            }
          }

          if (!recipientFound)
          {
            cout << "\nNo client found with ID: " << recipientId << ". Transfer canceled." << endl;
          }

          break;
        }

        case 4:
          updatePassword(client);
          break;
        case 5:
          client->displayMyInfo();
          break;
        case 6:
        {
          return true;
        }
        default:
          cout << "Invalid choice. Please try again." << endl;
        }
      }
      catch (const invalid_argument &)
      {
        cout << "Invalid choice. Please try again." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  }
  else
  {
    cout << "Login failed. Invalid ID or password." << endl;
    return false;
  }
}

//* deposit
void ClientManager::deposit(Client &client, double amount)
{
  vector<Client> clients = FilesHelper::getClients();

  for (auto &c : clients)
  {
    if (c.getId() == client.getId())
    {
      if (amount > 0)
      {
        double balance = c.getBalance();

        balance += amount;

        c.setBalance(balance);
        cout << "Deposit successful. New balance : " << c.getBalance() << endl;
      }
      else
      {
        cout << "Invalid deposit amount." << endl;
      }
      break;
    }
  }

  FilesHelper::updateClientFile(clients);
}

//* withdraw
void ClientManager::withdraw(Client &client, double amount)
{
  vector<Client> clients = FilesHelper::getClients();

  for (auto &c : clients)
  {
    if (c.getId() == client.getId())
    {
      double balance = c.getBalance();
      if (amount > 0 && balance - amount >= 1500)
      {

        balance -= amount;

        c.setBalance(balance);
        cout << "Withdraw successful. New balance : " << c.getBalance() << endl;
      }
      else
      {
        cout << "Invalid deposit amount." << endl;
      }
      break;
    }
  }

  FilesHelper::updateClientFile(clients);
}

//* transfer to
void ClientManager::transferTo(Client &client, double amount, Client &recipient)
{
  cout << "=============== \n\n";
  vector<Client> clients = FilesHelper::getClients();

  for (auto &c : clients)
  {
    if (c.getId() == client.getId())
    {
      double balance = c.getBalance();

      if (amount > 0 && balance - amount >= 1500)
      {
        balance -= amount;
        c.setBalance(balance);

        for (auto &r : clients)
        {
          if (r.getId() == recipient.getId())
          {
            r.setBalance(r.getBalance() + amount);
            cout << "Transfer successful. New balance : " << c.getBalance() << " EGP " << endl;
            break;
          }
        }
      }
      else
      {
        cout << "Invalid transfer amount or insufficient balance." << endl;
      }
      break;
    }
  }

  FilesHelper::updateClientFile(clients);
}
