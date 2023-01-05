#ifndef USUARIO_H
#define USUARIO_H

#include <QObject>


class usuario
{
public:
    usuario(QString user, QString clave);
    //set
    void setUser(QString user);
    void setClave(QString clave);
    //get
    QString getUser();
    QString getClave();
private:
    QString user;
    QString clave;
};

#endif // USUARIO_H
