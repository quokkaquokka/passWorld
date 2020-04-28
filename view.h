#ifndef VIEW
#define VIEW

#include "site.h"
#include "display.h"
#include "editor.h"
#include "account.h"
#include "database.h"

#include <QList>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QString>
#include <QPushButton>

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = 0);
    ~View();

    static void identify(const int i);
    static int i;
    static QPushButton *save1;

    static QPushButton *save3;
    static QPushButton *save4;
    static QPushButton *save5;
    static QPushButton *save6;

    static Account deleteaccountname;

    static QLineEdit* message2;
    static QLineEdit* message;
    static QLineEdit* message3;
        static QLineEdit* message4;
            static QLineEdit* message5;

    static QGridLayout *layout;


public slots:
    static void addSite();
    static void addSiteEdit();

    static void deleteSite();
    static void deleteSiteEdit();

    static void addAccount();
    static void addAccountEdit();

    static void editAccount();
    static void editAccountEdit();

    static void deleteAccount();
    static void deleteAccountEdit();

private :
    //static QGridLayout *layout;

    static QLineEdit *addSiteName;
    static QLineEdit *addSiteAccount;
    static QLineEdit *addSitePassword;
    Display *display;
    QList<Site> list;

    static QLineEdit *deleteSiteName;

    static QLineEdit *addAccountsName;
    static QLineEdit *addAccountspassword;
    static QLineEdit *addAccountssite;


    static QLineEdit *editAccountName;
    static QLineEdit *editAccountsPassword;
    static QLineEdit *editAccountssite;

    static QLineEdit *deleteAccountName;
    static QLineEdit *deleteAccountSiteName;

};
#endif // VIEW

