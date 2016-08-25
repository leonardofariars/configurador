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

/*
    ManipuladorXML x;
    x.LeArquivo();
    ui->edt_nome->setText(x.getEmpresa());
    ui->edt_cnpj->setText(x.getCNPJ());
    ui->edt_telefone->setText(x.getTelefone());
    */
}

ManipuladorXML ConfigWindow::getManipuladorXML() const{
    return propXML;
}

ConfigWindow::~ConfigWindow()
{


    delete ui;

}

void ConfigWindow::on_buttonBox_accepted()
{
    ManipuladorXML leitor;
    leitor.LeArquivo();
    ui->edt_nome->setText(leitor.getEmpresa());
    ui->edt_cnpj->setText(leitor.getCNPJ());
    ui->edt_telefone->setText(leitor.getTelefone());
}
