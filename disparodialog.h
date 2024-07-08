#ifndef DISPARODIALOG_H
#define DISPARODIALOG_H

#include <QDialog>

namespace Ui {
class DisparoDialog;
}

class DisparoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DisparoDialog(QWidget *parent = nullptr);
    ~DisparoDialog();

    void setDisparo(bool disparo);
    void setPersonaElegida(std::string persona);

    bool getDisparo();

private slots:
    void on_pushButtonSi_clicked();

    void on_pushButtonNo_clicked();

private:
    Ui::DisparoDialog *ui;
    bool disparo;
};

#endif // DISPARODIALOG_H
