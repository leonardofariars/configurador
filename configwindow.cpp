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

void ConfigWindow::avancaPagina(){
    ui->tbx_paginas->setCurrentIndex(
        ui->tbx_paginas->currentIndex() + 1 );
}

void ConfigWindow::retornaPagina(){
    ui->tbx_paginas->setCurrentIndex(
        ui->tbx_paginas->currentIndex() - 1 );
}

ConfigWindow::~ConfigWindow()
{


    delete ui;

}

void ConfigWindow::on_buttonBox_accepted()
{
    ManipuladorXML leitor;
    //leitor.LeArquivo();
    //leitor.LeArquivo2(QString );
    ui->edt_nome->setText(leitor.getEmpresa());
    ui->edt_cnpj->setText(leitor.getCNPJ());
    ui->edt_telefone->setText(leitor.getTelefone());
}
