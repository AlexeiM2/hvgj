#include "agregar_categoria.h"
#include "ui_agregar_categoria.h"

Agregar_categoria::Agregar_categoria(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Agregar_categoria)
{
    ui->setupUi(this);
}

Agregar_categoria::~Agregar_categoria()
{
    delete ui;
}

void Agregar_categoria::on_pushButton_clicked()
{
    close();
}


void Agregar_categoria::on_pushButton_2_clicked()
{
    close();
}

