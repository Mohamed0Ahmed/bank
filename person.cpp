#include <iostream>
using namespace std;

#include "person.h"
#include "validation.h"

Person::Person(int id, const string &name, const string &password)
    : id(id), name(name), password(password) {}

int Person::getId() const
{
    return id;
}

void Person::setId(int id)
{
    this->id = id;
}
double Person::getBalance() const
{
    return balance;
}


const string &Person::getName() const
{

    return name;
}

void Person::setName(const string &name)
{

    getline(cin, this->name);

    //* Check
    if (!Validation::checkName(this->name))
    {
        cout << "Invalid name . ";
    }

    //* continue asking
    while (!Validation::checkName(this->name))
    {
        cout << "Enter New Name : ";
        getline(cin, this->name);
    }
}

const string &Person::getPassword() const
{

    return password;
}

void Person::setPassword(const string &password)
{

    cin >> this->password;
    //* Check
    if (!Validation::checkPassword(this->password))
    {
        cout << "Password must be atleast 8 characters,\n";
    }

    //* continue asking
    while (!Validation::checkPassword(this->password))
    {
        cout << "Enter New Password : ";
        cin >> this->password;
    }
}