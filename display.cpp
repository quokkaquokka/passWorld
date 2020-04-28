#include "display.h"
#include "database.h"
#include "password.h"
#include "view.h"

//QGridLayout* Display::layout;
QListWidget* Display::sites;

Display::Display(QWidget *parent)
    : QWidget(parent)
{
   layout = new QGridLayout(this);
    setLayout(layout);

    //sites = new QListWidget(this);
    sites = new QListWidget;
    accounts = new QListWidget(this);
    password = new QLineEdit(this);

    password->setReadOnly(true);

   // layout->addWidget(sites, 0, 0, 20, 3);
    //layout->addWidget(accounts, 0, 3, 19, 3);
    //layout->addWidget(password, 19, 3, 1, 3);
    View::layout->addWidget(sites, 0, 0, 20, 3);
    View::layout->addWidget(accounts, 0, 3, 19, 3);
    View::layout->addWidget(password, 19, 3, 1, 3);



    fDisplaySite();
    connect(sites, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(fDisplayAccounts(QListWidgetItem*)));

    connect(accounts, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(displayPassword(QListWidgetItem*)));
}

Display::~Display()
{
    delete layout;
    layout = 0;
    delete sites;
    sites = 0;
    delete accounts;
    accounts = 0;
    delete password;
    password = 0;
}

void Display::fDisplaySite()
{
    QList<Site>  site;
    site = Database::selectAll();

    if (!site.empty())
    {
        for(int i = 0; i < site.size(); i++)
        {
            Display::sites->addItem(site.at(i).getName());
        }
    }
}

void Display::fDisplayAccounts(QListWidgetItem* item)
{
    accounts->clear();
    QList<Site>  site;
    site = Database::selectAll();
    nameSite = item->text();

    if (!site.empty())
    {
        int i = 0;

        while((item->text()) != site.at(i).getName())
        {
            i = i + 1;
        }
        QList<Account> accountsList;
        accountsList = site.at(i).getAccounts();

        if (!accountsList.empty())
        {
            for(int j = 0; j < accountsList.size(); j++)
            {
                accounts->addItem(accountsList.at(j).getName());
            }
        }
    }
}

void Display::displayPassword(QListWidgetItem* item)
{
    QList<Site>  site;
    site = Database::selectAll();

    if (!site.empty())
    {
        int i = 0;

        while(nameSite != site.at(i).getName())
        {
            i = i + 1;
        }

        QList<Account> accounts;
        accounts = site.at(i).getAccounts();

        if(!accounts.empty())
        {
            int j = 0;

            while((item->text()) != accounts.at(j).getName())
            {
                j = j + 1;
            }

            QString decrypt = Password::passwordEcrypt(accounts.at(j).getPassword());
            password->setText(decrypt);
        }
    }
}
