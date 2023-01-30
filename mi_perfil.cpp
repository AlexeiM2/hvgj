#include "mi_perfil.h"
#include "ui_mi_perfil.h"
#include <pantalla_principal.h>
#include "pantalla_principal.h"
#include "ui_pantalla_principal.h"
#include "widget.h"
#include "mi_perfil.h"
#include <QMessageBox>
#include <QDebug>
#include <string>

Mi_perfil::Mi_perfil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mi_perfil)
{
    ui->setupUi(this);
}

Mi_perfil::~Mi_perfil()
{
    delete ui;
}


void Mi_perfil::on_btnsalir_clicked()
{
    close();
    Widget *ventana1= new Widget;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();

}

void Mi_perfil::on_btnregresar_clicked()
{
    close();
    Pantalla_principal *ventana1 = new Pantalla_principal("");
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();
}

