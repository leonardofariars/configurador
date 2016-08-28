#include "configwindow.h"
#include "ui_configwindow.h"
#include <QFileDialog>
#include <QMessageBox>



ConfigWindow::ConfigWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigWindow)



{
    ui->setupUi(this);

    ManipuladorXML leitor;
    leitor.LeArquivo(".//config.xml");

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
    ManipuladorXML gravador;
    gravador.GravaArquivo();

}

void ConfigWindow::on_commandLinkButton_clicked(){
    avancaPagina();
}

void ConfigWindow::on_commandLinkButton_2_clicked(){
    avancaPagina();
}

void ConfigWindow::on_commandLinkButton_3_clicked()
{
    retornaPagina();
}
