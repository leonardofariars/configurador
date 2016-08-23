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


    ~ConfigWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConfigWindow *ui;
    ManipuladorXML propXML;
};

#endif // CONFIGWINDOW_H
