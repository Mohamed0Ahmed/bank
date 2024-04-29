#include "fileManager.h"
#include "parser.h"
#include "filehelper.h"

//* add client
void FileManager::addClient(const Client &c)
{
  FilesHelper::saveClient("Clients.txt", "lastClientId.txt", c);
}

//* add employee
void FileManager::addEmployee(const Employee &e)
{
  FilesHelper::saveEmployee("Employees.txt", "lastEmployeeId.txt", e);
}

//* add admin
void FileManager::addAdmin(const Admin &a)
{
  FilesHelper::saveEmployee("Admins.txt", "lastAdminId.txt", a);
}

//* get all clients
void FileManager::getAllClients()
{
  FilesHelper::getClients();
}

//* get all Employee
void FileManager::getAllEmployees()
{
  FilesHelper::getEmployees();
}

//* get all admins
void FileManager::getAllAdmins()
{
  FilesHelper::getAdmins();
}

void FileManager::removeAllClients()
{
  FilesHelper::clearFile("Clients.txt", "lastClientId.txt");
}

void FileManager::removeAllEmployees()
{
  FilesHelper::clearFile("Employees.txt", "lastEmployeeId.txt");
}

void FileManager::removeAllAdmins()
{
  FilesHelper::clearFile("Admins.txt", "lastAdminId.txt");
}

void FileManager::updateClients(){
  FilesHelper::updateClientFile(clients);
} ;
