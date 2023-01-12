#include "dialog_miembro.h"
#include "ui_dialog_miembro.h"

Dialog_miembro::Dialog_miembro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_miembro)
{
    ui->setupUi(this);
}

Dialog_miembro::~Dialog_miembro()
{
    delete ui;
}

void Dialog_miembro::on_buttonBox_accepted()
{
    QString nombre = ui->Inrol->text();
    QString apellido = ui->Innombre->text();
    QString telefono = ui->Inapellido->text();
    QString email = ui->Inedad->text();
    this->m_miembro = new Miembro_f(nombre, apellido, telefono, email);

}


void Dialog_miembro::on_buttonBox_rejected()
{
    reject();

}

Miembro_f *Dialog_miembro::miembro() const
{
    return m_miembro;

}


