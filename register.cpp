#include "register.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <widget.h>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;

}

void Register::on_btncuenta_clicked()
{
    Widget *ventana1= new Widget;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();

}
