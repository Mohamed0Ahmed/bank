#include "dataSourceInterface.h"
#include "fileManager.h"


void DataSourceInterface::addClient(const Client &c)
{
  FileManager fileManager;
  fileManager.addClient(c);
}

void DataSourceInterface::addEmployee(const Employee &e)
{
  FileManager fileManager;
  fileManager.addEmployee(e);
}

void DataSourceInterface::addAdmin(const Admin &a)
{
  FileManager fileManager;
  fileManager.addAdmin(a);
}

void DataSourceInterface::getAllClients()
{
  FileManager fileManager;
  fileManager.getAllClients();
}

void DataSourceInterface::getAllEmployees()
{
  FileManager fileManager;
  fileManager.getAllEmployees();
}

void DataSourceInterface::getAllAdmins()
{
  FileManager fileManager;
  fileManager.getAllAdmins();
}

void DataSourceInterface::removeAllClients()
{
  FileManager fileManager;
  fileManager.removeAllClients();
}

void DataSourceInterface::removeAllEmployees()
{
  FileManager fileManager;
  fileManager.removeAllEmployees();
}

void DataSourceInterface::removeAllAdmins()
{
  FileManager fileManager;
  fileManager.removeAllAdmins();
}
