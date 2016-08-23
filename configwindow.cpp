#include "configwindow.h"
#include "ui_configwindow.h"
#include <QFileDialog>
#include <QMessageBox>


ConfigWindow::ConfigWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
    //ui->edt_nome->setText(propXML.getEmpresa());
}

ManipuladorXML ConfigWindow::getManipuladorXML() const{
    return propXML;
}

ConfigWindow::~ConfigWindow()
{
    delete ui;
    ui->edt_end1->setText(propXML.getEnd1());
    ui->edt_end2->setText(propXML.getEnd2());
}

void ConfigWindow::on_buttonBox_accepted()
{
    propXML.setEmpresa(ui->edt_nome->text());
    propXML.setTelefone(ui->edt_telefone->text());
    propXML.setCNPJ(ui->edt_cnpj->text());
    propXML.setEnd1(ui->edt_end1->text());
    propXML.setEnd2(ui->edt_end2->text());
    propXML.setNMesas(ui->spn_mesas->value());
    propXML.setCalcTX(ui->chkCalcTX->isChecked());
    propXML.setTXServ(ui->dblspnTXServ->value());
    propXML.setTXProm(ui->edt_txtprom->text());
	// teste de commit
    // mais um teste de commit.

}
