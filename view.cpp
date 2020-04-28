#include "view.h"
#include "display.h"
#include "editor.h"
#include "menu.h"
#include "account.h"
#include "site.h"
#include "database.h"
#include "password.h"
#include <QPushButton>
#include <QLayout>
#include <QLineEdit>
#include <QDebug>

QGridLayout* View::layout;

QPushButton* View::save1;
QPushButton* View::save3;
QPushButton* View::save4;
QPushButton* View::save5;
QPushButton* View::save6;
QLineEdit* View::addSiteName;
QLineEdit* View::addSiteAccount;
QLineEdit* View::addSitePassword;

QLineEdit* View::deleteSiteName;

QLineEdit* View::addAccountsName;
QLineEdit* View::addAccountspassword;
QLineEdit* View::addAccountssite;
QLineEdit* View::message2;
QLineEdit* View::message;
QLineEdit* View::message3;
QLineEdit* View::message4;
QLineEdit* View::message5;

QLineEdit* View::editAccountName;
QLineEdit* View::editAccountsPassword;
QLineEdit* View::editAccountssite;

QLineEdit* View::deleteAccountName;
QLineEdit* View::deleteAccountSiteName;
int View::i;
Account View::deleteaccountname;


View::View(QWidget *parent) :
    QWidget(parent)
{
    layout = new QGridLayout(this);
    display = new Display(this);

    layout->addWidget(display, 0, 0);

    i = 0;
}

View::~View()
{
    delete display;
    display = 0;
    delete layout;
    layout = 0;
}

void View::identify(const int i)
{
    if (i == 1)
    {
        delete addSiteName;
        addSiteName = 0;
        delete addSiteAccount;
        addSiteAccount = 0;
        delete addSitePassword;
        addSitePassword = 0;
        delete save1;
        save1 = 0;
    }
    else if(i == 3)
    {
        delete deleteSiteName;
        deleteSiteName = 0;
        delete save3;
        save3 = 0;
    }
    else if(i == 4)
    {
        delete addAccountsName;
        addAccountsName = 0;
        delete addAccountspassword;
        addAccountspassword = 0;
        delete addAccountssite;
        addAccountssite = 0;
        delete save4;
        save4 = 0;
    }
    else if(i == 5)
    {
        delete editAccountName;
        editAccountName = 0;
        delete editAccountssite;
        editAccountssite = 0;
        delete editAccountsPassword;
        editAccountsPassword = 0;
        delete save5;
        save5 = 0;
    }
    else if(i == 6)
    {
        delete deleteAccountName;
        deleteAccountName = 0;
        delete save6;
        save6 = 0;
    }
}

void View::addSite()
{
    identify(i);
    i = 1;

    addSiteName = new QLineEdit;
    layout->addWidget(addSiteName ,0 ,10);
    addSiteName->setPlaceholderText("name of the Site");

    addSiteAccount = new QLineEdit;
    addSiteAccount->setPlaceholderText("name of the account");
    layout->addWidget(addSiteAccount, 1, 10);

    addSitePassword = new QLineEdit;
    addSitePassword->setPlaceholderText("Password");
    layout->addWidget(addSitePassword, 2, 10);


    save1 = new QPushButton("Save");
    layout->addWidget(save1, 3, 10);
}


void View::addSiteEdit()
{
    QList<Site> listSites;
    listSites = Database::selectAll();

    if (!listSites.empty())
    {
        int i = 0;
        bool exist = false;

        while(i < listSites.length())
        {
            if (addSiteName->text() == listSites.at(i).getName())
            {
                exist = true;
            }
            i = i + 1;
        }
        if(exist)
        {
            message3 = new QLineEdit;
            layout->addWidget(message3, 5, 10);
            message3->setPlaceholderText("the site exist");
            message3->setReadOnly(true);
        }
        else
        {
    Site newsite;
    newsite.setName(addSiteName->text());

    Database::insert(newsite);

    QList<Site> listSite;
    listSite = Database::selectAll();


    if (!listSite.empty())
    {
        int i = 0;

        while(addSiteName->text() != listSite.at(i).getName())
        {
            if (addSiteName->text() != listSite.at(i).getName())
            i = i + 1;
        }

        Account newaccount;

        newaccount.setName(addSiteAccount->text());

        QString password = addSitePassword->text();
        QString encrypt = Password::passwordEcrypt(password);

        newaccount.setPassword(encrypt);
        newaccount.setId(listSite.at(i).getId());

        Database::insert(newaccount, newsite);
        Display::sites->clear();
        Display::fDisplaySite();
    }
    }
    }
}

void View::deleteSite()
{
    identify(i);
    i = 3;

    deleteSiteName = new QLineEdit;
    layout->addWidget(deleteSiteName, 0, 10);
    deleteSiteName->setPlaceholderText("Name of the Site");

    save3 = new QPushButton("Save");
    layout->addWidget(save3,1, 10);
}

void View::deleteSiteEdit()
{
    QList<Site> listSite;
    listSite = Database::selectAll();

    if (!listSite.empty())
    {
        int i = 0;

        while(deleteSiteName->text() != listSite.at(i).getName())
        {
            i = i + 1;
        }

        Database::remove(listSite.at(i));
        Display::sites->clear();
        Display::fDisplaySite();
    }
}

void View::addAccount()
{
    identify(i);
    i = 4;

    addAccountssite = new QLineEdit;
    layout->addWidget(addAccountssite, 2, 10);
    addAccountssite->setPlaceholderText("Name of the site to add account");

    addAccountsName = new QLineEdit;
    layout->addWidget(addAccountsName, 3, 10);
    addAccountsName->setPlaceholderText("Name of th Account");

    addAccountspassword = new QLineEdit;
    layout->addWidget(addAccountspassword, 4, 10);
    addAccountspassword->setPlaceholderText("Password");


    save4 = new QPushButton("Save");
    layout->addWidget(save4,5,10);

}

void View::addAccountEdit()
{
    QList<Site> listSite;
    listSite = Database::selectAll();

    if (!listSite.empty())
    {
        int i = 0;
        int j;
        bool exist = true;

        while(i < listSite.length())
        {
            if (addAccountssite->text() == listSite.at(i).getName())
            {
                exist = false;
                j = i;
            }

            i = i + 1;


        }

        if (exist == false)
        {
            QList<Account> accounts;
            accounts = listSite.at(j).getAccounts();

            int h = 0;
            bool exitaccount = true;
            int g;

            while(h < accounts.length())
            {
                if (addAccountsName->text() == accounts.at(h).getName())
                {
                    exitaccount = false;
                    g = h;
                }

                h = h + 1;
            }
            if(exitaccount == false)
            {
                message2 = new QLineEdit;
                layout->addWidget(message2, 7, 10);
                message2->setPlaceholderText("the account exist");
                message2->setReadOnly(true);
            }
            else
            {
                Account account;

                account.setName(addAccountsName->text());
                account.setPassword(addAccountspassword->text());
                account.setId(listSite.at(j).getId());

                Database::insert(account, listSite.at(j));

                addAccountssite->close();
                addAccountsName->close();
                addAccountspassword->close();
                save4->close();

            }

        }

        else
        {
            message = new QLineEdit;
            layout->addWidget(message, 6, 10);
            message->setPlaceholderText("the site does not exist");
            message->setReadOnly(true);
        }

    }
}

void View::editAccount()
{
    identify(i);
    i = 5;

    editAccountssite = new QLineEdit;
    layout->addWidget(editAccountssite,1,10);
    editAccountssite->setPlaceholderText("Site name");

    editAccountName = new QLineEdit;
    layout->addWidget(editAccountName,2,10);
    editAccountName->setPlaceholderText("account name to change");

    editAccountsPassword = new QLineEdit;
    layout->addWidget(editAccountsPassword,3,10);
    editAccountsPassword->setPlaceholderText("the password to change");

    save5 = new QPushButton("Save");
    layout->addWidget(save5,4,10);
}
void View::editAccountEdit()
{
    QList<Site> listSite;
    listSite = Database::selectAll();
    bool exist = false;
    if (!listSite.empty())
    {
        int i = 0;

        while(editAccountssite->text() != listSite.at(i).getName())
        {
            if(editAccountssite->text() != listSite.at(i).getName())
            {
                    exist = true;
        }

            i = i + 1;
        }

        if (exist)
        {
            message4 = new QLineEdit;
            layout->addWidget(message4, 5, 10);
            message4->setPlaceholderText("the site does not exist");
            message4->setReadOnly(true);
        }
        else
        {
            QList<Account> listAccounts;
            listAccounts = listSite.at(i).getAccounts();

            if (!listAccounts.empty())
            {
                int j = 0;

                while(editAccountName->text() != listAccounts.at(j).getName())
                {
                    j = j + 1;
                }
                if ((editAccountName->text() != listAccounts.at(j).getName()) && (i == listSite.length()))
                {
                    // message d'erreur;
                    message5 = new QLineEdit;
                    layout->addWidget(message5, 5, 10);
                    message5->setPlaceholderText("the account does not exist");
                    message5->setReadOnly(true);
                }
                else
                {
                    Account account;
                    account = listAccounts.at(j);
                    account.setPassword(editAccountsPassword->text());
                    QString password = Password::passwordEcrypt(editAccountsPassword->text());

                    Database::update(listAccounts.at(j), password);
                }
            }
        }
    }
}

void View::deleteAccount()
{
    identify(i);
    i = 6;

    deleteAccountSiteName = new QLineEdit;
    layout->addWidget(deleteAccountSiteName, 1, 10);
    deleteAccountSiteName->setPlaceholderText("Name of thse Site");

    deleteAccountName = new QLineEdit;
    layout->addWidget(deleteAccountName, 2, 10);
    deleteAccountName->setPlaceholderText("Name of the Accounts to delete");

    save6 = new QPushButton("Save");
    layout->addWidget(save6,3, 10);
}

void View::deleteAccountEdit()
{
    QList<Site> listSite;
    listSite = Database::selectAll();

    if (!listSite.empty())
    {
        int i = 0;

        while(deleteAccountSiteName->text() != listSite.at(i).getName())
        {
            i = i + 1;
        }
        QList<Account> listAccounts;
        listAccounts = listSite.at(i).getAccounts();
        if (!listAccounts.empty())
        {
            int j = 0;

            while(deleteAccountName->text() != listAccounts.at(j).getName())
            {
                j = j + 1;
            }
            Database::remove(listAccounts.at(j));
        }
    }
}



