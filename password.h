#ifndef PASSWORD
#define PASSWORD

#include <QString>

class Password
{
public:
    Password();
    ~Password();

    static QString passwordEcrypt(QString password);
};
#endif // PASSWORD

