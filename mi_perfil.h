#ifndef MI_PERFIL_H
#define MI_PERFIL_H

#include <QWidget>

namespace Ui {
class Mi_perfil;
}

class Mi_perfil : public QWidget
{
    Q_OBJECT

public:
    explicit Mi_perfil(QWidget *parent = nullptr);
    ~Mi_perfil();

private slots:
    void on_btnsalir_clicked();

private:
    Ui::Mi_perfil *ui;
};

#endif // MI_PERFIL_H