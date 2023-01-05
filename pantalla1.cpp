#include "pantalla1.h"
#include "ui_pantalla1.h"
#include <QMessageBox>
#include <QDebug>
pantalla1::pantalla1(QString usuario,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantalla1)
{
    ui->setupUi(this);
    ui->lblsetusuario->setText(usuario);
    usuario1=usuario;
}

pantalla1::~pantalla1()
{
    delete ui;
}

void pantalla1::on_btnsalir_clicked()
{
    close();
}


void pantalla1::on_btnmensaje_clicked()
{
    QMessageBox::information(this,"Aviso",usuario1);
}

void pantalla1::on_actionAcerca_de_triggered()
{
    // Crear un objeto del cuadro de diálogo
    Acerca *dialog = new Acerca(this);
    // Enviar datos a la otra ventana
    dialog->setVersion(VERSION);
    // Mostrar la venta en modo MODAL
    dialog->exec();
    // Luego de cerrar la ventana, se acceden a los datos de la misma
    qDebug() << dialog->valor();

}
