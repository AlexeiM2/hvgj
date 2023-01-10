#ifndef PANTALLA_PRINCIPAL_H
#define PANTALLA_PRINCIPAL_H

#include <QMainWindow>
#include "acerca.h"
#define VERSION "0.2"

namespace Ui {
class Pantalla_principal;
}

class Pantalla_principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pantalla_principal(QString usuario, QWidget *parent = nullptr);

    ~Pantalla_principal();

private slots:


    void on_pushButton_3_clicked();

private:
    Ui::Pantalla_principal *ui;
    QString usuario1;
};

#endif // PANTALLA_PRINCIPAL_H
