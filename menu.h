#ifndef MENU
#define MENU

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QLineEdit>
#include <QLayout>
#include <QWidget>
#include <QListWidget>
#include <QList>
#include "view.h"

class Menu : public QMenuBar
{
    Q_OBJECT

public:
    Menu(QWidget *parent = 0);
    ~Menu();

public slots:
    void fAddSite();
    void fAddSiteEdit();

    void fDeleteSite();
    void fDeleteSiteEdit();

    void fAddAccount();
    void fAddAccountEdit();

    void fEditAccount();
    void fEditAccountEdit();

    void fDeleteAccount();
    void fDeleteAccountEdit();



private:
    QMenu *sites = 0;
    QMenu *accounts = 0;
};
#endif // MENU

