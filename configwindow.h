#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QMainWindow>

#include "manipuladorxml.h"

namespace Ui {
class ConfigWindow;
}

class ConfigWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConfigWindow(QWidget *parent = 0);
    ManipuladorXML getManipuladorXML() const;

    void avancaPagina();
    void retornaPagina();
    QString Criptografa (QString Texto);
    QString Descriptografa (QString Texto);
    int keymod [10]            = {29, 0, 67, 71, 3,10, 91, 3,21,60};
    int chaveCriptografia [10] = {64,35,102,106,48,75,126,38,56,95};
    //                         { @, #,  f,  j, 0, K,  ~, &, 8, _};

    //


    ~ConfigWindow();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_btn_grava_clicked();


    void on_pushButton_4_clicked();

private:
    Ui::ConfigWindow *ui;
    ManipuladorXML propXML;
};

#endif // CONFIGWINDOW_H
