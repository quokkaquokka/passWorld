#include "account.h"

Account::Account()
{

}

Account::~Account()
{

}

QString Account::getName() const
{
    return name;
}

void Account::setName(const QString name)
{
    this->name = name;
}

QString Account::getPassword() const
{
    return password;
}

void Account::setPassword(const QString password)
{
    this->password = password;
}

int Account::getId() const
{
    return id;
}

void Account::setId(const int id)
{
    this->id = id;
}
