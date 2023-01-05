#include "usuario.h"

usuario::usuario(QString user, QString clave)
{
    this->user=user;
    this->clave=clave;
}

void usuario::setUser(QString user)
{
    this->user=user;
}

void usuario::setClave(QString clave)
{
    this->clave=clave;
}

QString usuario::getUser()
{
    return this->user;
}

QString usuario::getClave()
{
    return this->clave;
}
