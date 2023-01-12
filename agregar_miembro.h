#ifndef AGREGAR_MIEMBRO_H
#define AGREGAR_MIEMBRO_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "dialog_miembro.h"
#include "miembro_f.h"

namespace Ui {
class Agregar_miembro;
}

class Agregar_miembro : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar_miembro(QWidget *parent = nullptr);

    ~Agregar_miembro();

private slots:
    void on_agregarboton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Agregar_miembro *ui;
    const QString ARCHIVO = "miembros.csv";
    enum Columna
    {
        ROL, NOMBRE, APELLIDO, EDAD
    };
    void cargar();
};

#endif // AGREGAR_MIEMBRO_H
