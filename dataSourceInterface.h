#pragma once

#include "client.h"
#include "employee.h"
#include "admin.h"

class DataSourceInterface
{
public:
  virtual void addClient(const Client &c) = 0;
  virtual void addEmployee(const Employee &e) = 0;
  virtual void addAdmin(const Admin &a) = 0;
  virtual void getAllClients() = 0;
  virtual void getAllEmployees() = 0;
  virtual void getAllAdmins() = 0;
  virtual void removeAllClients() = 0;
  virtual void removeAllEmployees() = 0;
  virtual void removeAllAdmins() = 0;
};
