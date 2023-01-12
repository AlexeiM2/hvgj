#include "agregar_miembro.h"
#include "ui_agregar_miembro.h"

Agregar_miembro::Agregar_miembro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar_miembro)
{
    ui->setupUi(this);
    setWindowTitle("Agenda telefónica");
    // Configurar la tabla
    //ui->tblLista->setColumnCount(4);
    ui->tbtLista->setColumnCount(4);
    QStringList titulo;
    titulo << "Rol" << "Nombre" << "Apellido" << "Edad";
    ui->tbtLista->setHorizontalHeaderLabels(titulo);
    // Leer desde el archivo
    cargar();
}

void Agregar_miembro::cargar()
{
    // Verificar si el archivo existe
    QFile archivo(ARCHIVO);
    if (!archivo.exists())
        return;

    // cargar datos
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->tbtLista->rowCount();
            ui->tbtLista->insertRow(fila);
            ui->tbtLista->setItem(fila, ROL, new QTableWidgetItem(datos[ROL]));
            ui->tbtLista->setItem(fila, NOMBRE, new QTableWidgetItem(datos[NOMBRE]));
            ui->tbtLista->setItem(fila, APELLIDO, new QTableWidgetItem(datos[APELLIDO]));
            ui->tbtLista->setItem(fila, EDAD, new QTableWidgetItem(datos[EDAD]));
        }
        archivo.close();
    }
}


Agregar_miembro::~Agregar_miembro()
{
    delete ui;
}




void Agregar_miembro::on_agregarboton_clicked()
{
    // Crear y mostrar el dialogo
    Dialog_miembro pd(this);
    pd.setWindowTitle("Agregar miembro");
    // Abrir la ventana y evaluar respuesta
    int res = pd.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar el objeto del cuadro de dialogo
    Miembro_f *m = pd.miembro();
    //Agregar a la tabla
    int fila = ui->tbtLista->rowCount();
    ui->tbtLista->insertRow(fila);
    ui->tbtLista->setItem(fila, ROL, new QTableWidgetItem(m->rol()));
    ui->tbtLista->setItem(fila, NOMBRE, new QTableWidgetItem(m->nombre()));
    ui->tbtLista->setItem(fila, APELLIDO, new QTableWidgetItem(m->apellido()));
    ui->tbtLista->setItem(fila, EDAD, new QTableWidgetItem(m->edad()));
}


void Agregar_miembro::on_buttonBox_accepted()
{
    // Verificar que exista datos para guardar
    int filas = ui->tbtLista->rowCount();
    if (filas == 0){
        QMessageBox::warning(this,"Guardar miembros","miembros sin datos para guardar");
        return;
    }
    // Abrir el archivo y guardar
    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *nombre = ui->tbtLista->item(i, ROL);
            QTableWidgetItem *apellido = ui->tbtLista->item(i, NOMBRE);
            QTableWidgetItem *telefono = ui->tbtLista->item(i, APELLIDO);
            QTableWidgetItem *email = ui->tbtLista->item(i, EDAD);
            salida << nombre->text() << ";" << apellido->text() << ";";
            salida << telefono->text() << ";" << email->text() << "\n";
        }
        archivo.close();
        QMessageBox::information(this,"Guardar miembros","Miembros guardados con éxito");
    }else{
        QMessageBox::critical(this,"Guardar miembros", "No se puede escribir sobre " + ARCHIVO);
    }
}


void Agregar_miembro::on_buttonBox_rejected()
{
    reject();
}

