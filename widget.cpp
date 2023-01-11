#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <pantalla_principal.h>
#include <register.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->txtpasword->setEchoMode(QLineEdit::Password);
    QFile archivo;
    QTextStream io;
    QString nombreArchivo=":/usuarios.csv";
    archivo.setFileName(nombreArchivo);//se indicaca el archico con el cual se va trabajar
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    //verificar si el archivo se habre
    if(!archivo.isOpen()){
        QMessageBox::information(this,"Error",archivo.errorString());
        return;
    }
    //QString user, password;
    io.setDevice(&archivo);
    while (!io.atEnd()) {//recorrer el archivo hasta que no sea fin de archivo
        auto linea=io.readLine();
        //qDebug()<<linea;
        auto valores=linea.split(";");
        //qDebug()<<valores;
        //qDebug()<<valores[0]<<"--"<<valores[1];
        m_usuario.append(new usuario(valores[0],valores[1]));
    }
    archivo.close();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnacceder_clicked()
{
    //Pantalla_principal *ventana1 = new Pantalla_principal(ui->txtusuario->text());
    //ventana1->setWindowModality(Qt::ApplicationModal);
    //ventana1->show();
    bool encontrado=false;
    for(int i=0; i<m_usuario.size();i++){
        //qDebug()<<m_usuario.at(i)->getUser()<<" - "<<m_usuario[i]->getClave();
        if(ui->txtusuario->text()==m_usuario.at(i)->getUser() &&
           ui->txtpasword->text()==m_usuario[i]->getClave()){
                encontrado=true;
                break;
        }
    }
    if (encontrado){
        qDebug()<<"Ok usuario registrado";
        Pantalla_principal *ventana1 = new Pantalla_principal(ui->txtusuario->text());
        ventana1->setWindowModality(Qt::ApplicationModal);
        ventana1->show();
    }else{
       qDebug()<<"Compruebe los datos e intente de nuevo";
       QMessageBox::critical(this,"Error","Compruebe los datos e intente de nuevo");
    }

}

void Widget::on_btnregistrarse_clicked()
{
    Register *ventana1= new Register;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();

}


void Widget::on_btnacceder2_clicked()
{

    QFile archivo;
    QTextStream io;
    QString nombreArchivo=":/usuarios.csv";
    archivo.setFileName(nombreArchivo);//se indicaca el archico con el cual se va trabajar
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    //verificar si el archivo se habre
    if(!archivo.isOpen()){
        QMessageBox::information(this,"Error",archivo.errorString());
        return;
    }
    //QString user, password;
    io.setDevice(&archivo);
    bool encontrado=false;
    while (!io.atEnd()) {//recorrer el archivo hasta que no sea fin de archivo
        auto linea=io.readLine();
        //qDebug()<<linea;
        auto valores=linea.split(";");
        if(ui->txtusuario->text()==valores[0] &&
           ui->txtpasword->text()==valores[1]){
                encontrado=true;
                break;
        }
    }
    archivo.close();
    if (encontrado){
        qDebug()<<"Ok usuario registrado";
        Pantalla_principal *ventana1 = new Pantalla_principal(ui->txtusuario->text());
        ventana1->setWindowModality(Qt::ApplicationModal);
        ventana1->show();
    }else{
       qDebug()<<"Compruebe los datos e intente de nuevo";
       QMessageBox::critical(this,"Error","Compruebe los datos e intente de nuevo");
    }
}
