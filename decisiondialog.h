#ifndef DECISIONDIALOG_H
#define DECISIONDIALOG_H

#include <QDialog>
#include <string>


namespace Ui {
class DecisionDialog;
}

class DecisionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DecisionDialog(QWidget *parent = nullptr);
    ~DecisionDialog();
    void setPersona(std::string persona);
    void setProbabilidad(float prob);
    void setPersonaElegida(std::string persona);
    void setDisparo(bool disparo);

    bool getDisparo();
    std::string getPersonaElegida();

private slots:

    void on_pushButtonDealer_clicked();

    void on_pushButtonPlayer_clicked();

private:
    Ui::DecisionDialog *ui;
    std::string personaElegida;
    bool disparo;
};

#endif // DECISIONDIALOG_H
