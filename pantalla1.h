#ifndef PANTALLA1_H
#define PANTALLA1_H

#include <QWidget>
#include "acerca.h"

#define VERSION "0.2"

namespace Ui {
class pantalla1;
}

class pantalla1 : public QWidget
{
    Q_OBJECT

public:
    explicit pantalla1(QString usuario, QWidget *parent = nullptr);
    ~pantalla1();

private slots:
    void on_btnsalir_clicked();

    void on_btnmensaje_clicked();

    void on_actionAcerca_de_triggered();

private:
    Ui::pantalla1 *ui;
    QString usuario1;
};

#endif // PANTALLA1_H
