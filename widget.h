#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <usuario.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnacceder_clicked();

    void on_btnacceder2_clicked();

    void on_btnregistrarse_clicked();


private:
    Ui::Widget *ui;
    QList <usuario*> m_usuario;//lista con estructura de la clase usuario
};
#endif // WIDGET_H
