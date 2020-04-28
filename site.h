#ifndef SITE
#define SITE

#include "account.h"
#include <QList>

class Site
{
public:
    Site();
    ~Site();

    QString getName() const;
    void setName(const QString name);

    QList<Account> getAccounts() const;
    void setAccounts(const QList<Account> accounts);
    void addAccount(const Account account);
    void removeAccount(const Account account);

    int getId() const;
    void setId(const int id);

private:
    QList<Account> accounts;
    QString name;
    int id;
};

#endif // SITE

