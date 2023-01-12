#ifndef DIALOG_MIEMBRO_H
#define DIALOG_MIEMBRO_H

#include <QDialog>
#include"miembro_f.h"

namespace Ui {
class Dialog_miembro;
}

class Dialog_miembro : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_miembro(QWidget *parent = nullptr);
    Miembro_f *miembro()const;
    ~Dialog_miembro();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();



private:
    Ui::Dialog_miembro *ui;
    Miembro_f *m_miembro;
};

#endif // DIALOG_MIEMBRO_H