#ifndef DATABASE
#define DATABASE

#include "site.h"
#include "account.h"
#include <QList>
#include <QVariantMap>
#include <QSqlDatabase>
#include <QString>

class Database
{
public:

    static void create();
    static void insert(const Site site);
    static void insert(const Account account, const Site site);
    static QList<Site> selectAll();
    static void remove(const Site site);
    static void remove(const Account account);

    static void update(const Account account, QString password);
};

#endif // DATABASE
