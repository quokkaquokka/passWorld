#include "database.h"
#include "site.h"
#include "account.h"
#include "view.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QList>
#include <QDebug>


void Database::create()
{
    {
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE", "PassWorld.sqlite");
        database.setDatabaseName("PassWorld.sqlite");

        if (database.open())
        {

            QSqlQuery query(database);
            query.prepare("CREATE TABLE IF NOT EXISTS sites ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "name VARCHAR(30) NOT NULL UNIQUE"
                          ");");
            query.exec();
            query.finish();

            query.prepare("CREATE TABLE IF NOT EXISTS accounts ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "name VARCHAR(30) NOT NULL,"
                          "password INTEGER NOT NULL,"
                          "site INTEGER NOT NULL"
                          ");");
            query.exec();
            database.close();
        }
    }
    QSqlDatabase::removeDatabase("PassWorld.sqlite");
}

void Database::insert(const Site site)
{
    {
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE", "PassWorld.sqlite");
        database.setDatabaseName("PassWorld.sqlite");

        if (database.open())
        {
            QSqlQuery query(database);

            if(query.prepare("INSERT INTO sites (name) VALUES (:name);"))
            {
                query.bindValue(":name", site.getName());
                query.exec();
            }

            database.close();
        }
    }

    QSqlDatabase::removeDatabase("PassWorld.sqlite");

}

void Database::insert(const Account account, const Site site)
{
    {
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE", "PassWorld.sqlite");
        database.setDatabaseName("PassWorld.sqlite");

        if (database.open())
        {


            QSqlQuery query(database);

            if (query.prepare("INSERT INTO accounts (name, password, site) VALUES (:name, :password, :site);"))
            {

                query.bindValue(":name", account.getName());
                query.bindValue(":password", account.getPassword());
                query.bindValue(":site", account.getId());
                query.exec();
            }

            database.close();
        }
    }

    QSqlDatabase::removeDatabase("PassWorld.sqlite");

}

QList<Site> Database::selectAll()
{
    QList<Site> list;

    {
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE", "PassWorld.sqlite");
        database.setDatabaseName("PassWorld.sqlite");

        if (database.open())
        {
            QSqlQuery qSite(database);

            if (qSite.prepare("SELECT * FROM sites"))
            {
                qSite.exec();

                while (qSite.next())
                {
                    QSqlRecord rSite = qSite.record();
                    Site site;

                    site.setName(rSite.value("name").toString());
                    site.setId(rSite.value("id").toInt());

                    QSqlQuery qAccount(database);

                    if (qAccount.prepare("SELECT * FROM accounts WHERE site=:id"))
                    {
                        qAccount.bindValue(":id", site.getId());
                        qAccount.exec();

                        while (qAccount.next())
                        {
                            QSqlRecord rAccount = qAccount.record();
                            Account account;

                            account.setId(rAccount.value("id").toInt());
                            account.setName(rAccount.value("name").toString());
                            account.setPassword(rAccount.value("password").toString());

                            site.addAccount(account);
                        }
                    }

                    list.append(site);
                }
            }

            database.close();
        }
    }

    QSqlDatabase::removeDatabase("PassWorld.sqlite");
    return list;
}


void Database::remove(const Site site)
{
    {
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE", "PassWorld.sqlite");
        database.setDatabaseName("PassWorld.sqlite");

        if (database.open())
        {
            QSqlQuery query(database);

            if(query.prepare("DELETE FROM accounts WHERE sites= :id;"))
            {
                query.bindValue(":id", site.getId());
                query.exec();
            }

            if (query.prepare("DELETE FROM sites WHERE id= :id"))
            {
                query.bindValue(":id", site.getId());
                query.exec();
            }
        }

        database.close();
    }

    QSqlDatabase::removeDatabase("PassWorld.sqlite");
}

void Database::remove(const Account account)
{
    {
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE", "PassWorld.sqlite");
        database.setDatabaseName("PassWorld.sqlite");

        if (database.open())
        {
            QSqlQuery query(database);

            if (query.prepare("DELETE FROM accounts WHERE id= :id"))
            {
                query.bindValue(":id", account.getId());
                query.exec();
            }
        }

        database.close();
    }
    QSqlDatabase::removeDatabase("PassWorld.sqlite");
}

void Database::update(Account account, QString password)
{
    {
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE", "PassWorld.sqlite");
        database.setDatabaseName("PassWorld.sqlite");

        if (database.open())
        {
            QSqlQuery query(database);

            if (query.prepare("UPDATE accounts SET password = :password WHERE id= :id"))
            {
                query.bindValue(":id", account.getId());
                account.setPassword(password);
                query.bindValue(":password", account.getPassword());
                query.exec();
            }

        }
          database.close();
    }
 QSqlDatabase::removeDatabase("PassWorld.sqlite");
}
