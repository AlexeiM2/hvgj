#ifndef AGREGAR_MIEMBRO_H
#define AGREGAR_MIEMBRO_H

#include <QDialog>

namespace Ui {
class Agregar_miembro;
}

class Agregar_miembro : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar_miembro(QWidget *parent = nullptr);
    ~Agregar_miembro();

private:
    Ui::Agregar_miembro *ui;
};

#endif // AGREGAR_MIEMBRO_H
