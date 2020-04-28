#ifndef DISPLAY
#define DISPLAY

#include "site.h"

#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QList>

class Display : public QWidget
{
    Q_OBJECT

public:
    Display(QWidget *parent = 0);
    ~Display();

    QString nameSite;

    static void fDisplaySite();

        static QListWidget *sites;

public slots:
    void fDisplayAccounts(QListWidgetItem* item);
    void displayPassword(QListWidgetItem* item);

private:
    QGridLayout *layout;

    QListWidget *accounts = 0;
    QLineEdit *password = 0;
};
#endif // DISPLAY

