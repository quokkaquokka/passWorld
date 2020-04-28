#include"password.h"
#include <QString>
#include <QDebug>

Password::Password()
{

}

Password::~Password()
{

}

QString Password::passwordEcrypt(QString password)
{
    QString test = "";
    int i = 0;
    while(i < password.length())
    {
      QChar key = 'y';
      QChar passwordQchar = password.at(i);
      char keyChar = key.toLatin1();
      char passwordChar = passwordQchar.toLatin1();
      char encryptChar = (keyChar)^(passwordChar);

      QString encryptString;
      encryptString = (QString)encryptChar;
      test = test + encryptString;

        i = i + 1;

    }
    return test;
}
