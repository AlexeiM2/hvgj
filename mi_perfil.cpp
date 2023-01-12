#include "mi_perfil.h"
#include "ui_mi_perfil.h"
#include <pantalla_principal.h>
#include <widget.h>

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
