#include "menu.h"
#include "editor.h"
#include "view.h"
#include <QAction>
#include <QList>
#include <QString>
#include <QDebug>

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>

Menu::Menu(QWidget *parent)
    : QMenuBar(parent)
{
    sites = new QMenu("Sites");
    QList<QAction *> sitesActions;
    sitesActions.append(new QAction("Add", sites));
    sitesActions.append(new QAction ("Remove", sites));

    accounts = new QMenu("Accounts");
    QList<QAction *> accountsActions;
    accountsActions.append(new QAction("Add", accounts));
    accountsActions.append(new QAction("Edit", accounts));
    accountsActions.append(new QAction("Remove", accounts));

    addMenu(sites);
    sites->addActions(sitesActions);
    addMenu(accounts);
    accounts->addActions(accountsActions);

    connect(sites->actions().at(0), SIGNAL(triggered(bool)), this, SLOT(fAddSite()));
    connect(sites->actions().at(1), SIGNAL(triggered(bool)), this, SLOT(fDeleteSite()));
    connect(accounts->actions().at(0), SIGNAL(triggered(bool)), this, SLOT(fAddAccount()));
    connect(accounts->actions().at(1), SIGNAL(triggered(bool)), this, SLOT(fEditAccount()));
    connect(accounts->actions().at(2), SIGNAL(triggered(bool)), this, SLOT(fDeleteAccount()));
}

Menu::~Menu()
{
    delete sites;
    sites = 0;
    delete accounts;
    accounts = 0;
}

void Menu::fAddSite()
{
    View::addSite();
    connect(View::save1, SIGNAL(clicked(bool)), this, SLOT(fAddSiteEdit()));
}

void Menu::fAddSiteEdit()
{
    View::addSiteEdit();
}

void Menu::fDeleteSite()
{
    View::deleteSite();
    connect(View::save3, SIGNAL(clicked(bool)), this, SLOT(fDeleteSiteEdit()));
}

void Menu::fDeleteSiteEdit()
{
    View::deleteSiteEdit();
}

void Menu::fAddAccount()
{
    View::addAccount();
    connect(View::save4, SIGNAL(clicked(bool)), this, SLOT(fAddAccountEdit()));
}

void Menu::fAddAccountEdit()
{
    View::addAccountEdit();
}

void Menu::fEditAccount()
{
    View::editAccount();
    connect(View::save5, SIGNAL(clicked(bool)), this, SLOT(fEditAccountEdit()));
}
void Menu::fEditAccountEdit()
{
    View::editAccountEdit();
}

void Menu::fDeleteAccount()
{
    View::deleteAccount();
    connect(View::save6, SIGNAL(clicked(bool)), this, SLOT(fDeleteAccountEdit()));
}

void Menu::fDeleteAccountEdit()
{
    View::deleteAccountEdit();
}
