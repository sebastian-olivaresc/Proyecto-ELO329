#ifndef WINROUND_H
#define WINROUND_H

#include <QDialog>

namespace Ui {
class WinRound;
}

class WinRound : public QDialog
{
    Q_OBJECT

public:
    explicit WinRound(QWidget *parent = nullptr);
    ~WinRound();

signals:
    void buttonClicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WinRound *ui;

};

#endif // WINROUND_H
