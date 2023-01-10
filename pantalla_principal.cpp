#include "pantalla_principal.h"
#include "ui_pantalla_principal.h"
#include "personadialog.h"
#include "principal.h"
#include <QMessageBox>
#include <QDebug>
Pantalla_principal::Pantalla_principal(QString usuario, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pantalla_principal)
{
    ui->setupUi(this);
    //ui->lblsetusuario->setText(usuario);
        usuario1=usuario;
}

Pantalla_principal::~Pantalla_principal()
{
    delete ui;
}

void Pantalla_principal::on_pushButton_4_clicked()
{
    Principal *ventana1 = new Principal;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();
}

