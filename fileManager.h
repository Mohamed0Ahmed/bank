#pragma once
#include "DataSourceInterface.h"

class FileManager : public DataSourceInterface
{
  private:
  vector<Client> clients;
public:
  void addClient(const Client &c) override;
  void addEmployee(const Employee &e) override;
  void addAdmin(const Admin &a) override;
  void getAllClients() override;
  void getAllEmployees() override;
  void getAllAdmins() override;
  void removeAllClients() override;
  void removeAllEmployees() override;
  void removeAllAdmins() override;
  void updateClients();
};
