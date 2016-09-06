#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

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

    ~ConfigWindow();

private slots:

//---- Botões para alternar páginas ----- +
//                                        |
    void on_pushButton_clicked();    //   |
    void on_pushButton_2_clicked();  //   |
    void on_pushButton_3_clicked();  //   |
//                                        |
//========================================+
    void on_btn_grava_clicked();

    void on_btn_tstcon_clicked();

private:
    Ui::ConfigWindow *ui;
    ManipuladorXML propXML;
    QSqlDatabase Banco;
};

#endif // CONFIGWINDOW_H
