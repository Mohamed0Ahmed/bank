#pragma once
#include <string>
using namespace std;
#include <vector>

#include "person.h"
#include "client.h"

class ClientManager
{
public:
  static void printClientMenu();
  static void updatePassword(Person *person);
  static Client *login(int id, string password);
  static bool clientOptions(Client *client);

  static void deposit(Client &client, double amount);
  static void withdraw(Client &client, double amount);
  static void transferTo(Client &client, double amount, Client &recipient);
};