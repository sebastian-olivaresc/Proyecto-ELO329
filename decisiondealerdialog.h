#ifndef DECISIONDEALERDIALOG_H
#define DECISIONDEALERDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class DecisionDealerDialog;
}

class DecisionDealerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DecisionDealerDialog(QWidget *parent = nullptr);
    ~DecisionDealerDialog();
    void setPersonaElegida(std::string persona);
    void setDisparo(bool disparo);

    bool getDisparo();
    std::string getPersonaElegida();

private slots:
    void on_pushButtonDealer_clicked();

    void on_pushButtonPlayer_clicked();

private:
    Ui::DecisionDealerDialog *ui;
    std::string personaElegida;
    bool disparo;
};

#endif // DECISIONDEALERDIALOG_H
