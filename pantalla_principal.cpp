#include "pantalla_principal.h"
#include "ui_pantalla_principal.h"
#include"agregar_miembro.h"
#include "widget.h"
#include "mi_perfil.h"
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


void Pantalla_principal::on_pushButton_3_clicked()
{
    Agregar_miembro *ventana1= new Agregar_miembro;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();
}

void Pantalla_principal::on_actionSalir_triggered()
{
    close();
    Widget *ventana1= new Widget;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();
}

void Pantalla_principal::on_actionAcerca_de_triggered()
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

void Pantalla_principal::on_actionMi_perfil_triggered()
{
    close();
    Mi_perfil *ventana1= new Mi_perfil;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();

}

