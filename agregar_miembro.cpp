#include "agregar_miembro.h"
#include "ui_agregar_miembro.h"

Agregar_miembro::Agregar_miembro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar_miembro)
{
    ui->setupUi(this);
}

Agregar_miembro::~Agregar_miembro()
{
    delete ui;
}
