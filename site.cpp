#include "site.h"

Site::Site()
{

}

Site::~Site()
{

}

QString Site::getName() const
{
  return name;
}

void Site::setName(const QString name)
{
    this->name = name;
}

QList<Account> Site::getAccounts() const
{
    return accounts;
}

void Site::setAccounts(const QList<Account> accounts)
{
   this->accounts = accounts;
}

void Site::addAccount(const Account account)
{
    accounts.append(account);
}

void Site::removeAccount(const Account account)
{
    for (int i = 0; i < accounts.length(); i++ )
    {
        if(accounts.at(i).getId() == account.getId())
        {
            accounts.removeAt(i);
        }
    }
}

int Site::getId() const
{
    return id;
}

void Site::setId(const int id)
{
    this->id = id;
}
