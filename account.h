#ifndef ACCOUNT
#define ACCOUNT

#include <QObject>
#include <QString>

class Account
{
public:
    Account();
    ~Account();

    QString getName() const;
    void setName(const QString name);
    QString getPassword()const;
    void setPassword(const QString password);
    int getId() const;
    void setId(const int id);

private:
    QString name;
    QString password;
    int id;
};

#endif // ACCOUNT

