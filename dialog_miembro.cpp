#include "dialog_miembro.h"
#include "ui_dialog_miembro.h"
#include <QRegExpValidator>
#include <QtCore>
#include <QtGui>

#define NOMBRE_RX "([a-zA-Z',.-]+( [a-zA-Z',.-]+)*){2,30}"

Dialog_miembro::Dialog_miembro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_miembro)
{
    ui->setupUi(this);
    //validar nombre y apellido no ingresar caracteres extraños
    QRegExp rxNombre(NOMBRE_RX) , rxApellido(NOMBRE_RX);
    QRegExpValidator *valinombre =new QRegExpValidator(rxNombre,this);
    QRegExpValidator *valiapellido =new QRegExpValidator(rxApellido,this);
    ui->Innombre->setValidator(valinombre);
    ui->Inapellido->setValidator(valiapellido);


}

Dialog_miembro::~Dialog_miembro()
{
    delete ui;
}

void Dialog_miembro::on_buttonBox_accepted()
{

    QString rol = ui->Inrol->currentText();
    if(rol.isEmpty()){
        return ;
    }
    QString nombre = ui->Innombre->text();
    if(nombre.isEmpty()){
        return ;
    }
    QString apellido = ui->Inapellido->text();
    if(apellido.isEmpty()){
        return ;
    }
    QString edad = ui->Inedad->text();
    if(edad.isEmpty()){
        return ;
    }
    this->m_miembro = new Miembro_f(rol,nombre, apellido, edad);

}


void Dialog_miembro::on_buttonBox_rejected()
{
    reject();

}

Miembro_f *Dialog_miembro::miembro() const
{
    return m_miembro;

}


