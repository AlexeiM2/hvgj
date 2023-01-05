#ifndef AGREGAR_CATEGORIA_H
#define AGREGAR_CATEGORIA_H

#include <QMainWindow>

namespace Ui {
class Agregar_categoria;
}

class Agregar_categoria : public QMainWindow
{
    Q_OBJECT

public:
    explicit Agregar_categoria(QWidget *parent = nullptr);
    ~Agregar_categoria();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Agregar_categoria *ui;
};

#endif // AGREGAR_CATEGORIA_H
