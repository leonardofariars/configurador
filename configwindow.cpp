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

    QString narq;
    narq = QDir::currentPath() + "/config.xml";

    leitor.LeArquivo(narq);
    ui->edt_nmempresa->setText(leitor.getEmpresa());
    ui->edt_cnpj->setText(leitor.getCNPJ());
    ui->edt_fnemp->setText(leitor.getTelefone());
    ui->edt_end1->setText(leitor.getEnd1());
    ui->edt_end2->setText(leitor.getEnd2());
    ui->chk_calcServ->setChecked(leitor.getCalcTX());
    ui->edt_percServ->setValue(leitor.getTXServ());
    ui->edt_numMesa->setValue(leitor.getNMesas());
    ui->edt_msg1->setText(leitor.getMsg1());
    ui->edt_msg2->setText(leitor.getMsg2());


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

ConfigWindow::~ConfigWindow(){
    delete ui;
}


void ConfigWindow::on_pushButton_clicked(){
    avancaPagina();
}

void ConfigWindow::on_pushButton_2_clicked(){
    avancaPagina();
}

void ConfigWindow::on_pushButton_3_clicked(){
    retornaPagina();
}

void ConfigWindow::on_btn_grava_clicked()
{
    ManipuladorXML gravador;
    // Empresa
    gravador.setEmpresa(ui->edt_nmempresa->text());
    gravador.setTelefone(ui->edt_fnemp->text());
    gravador.setCNPJ(ui->edt_cnpj->text());
    gravador.setEnd1(ui->edt_end1->text());
    gravador.setEnd2(ui->edt_end2->text());

    // Atendimento
    gravador.setNMesas(ui->edt_numMesa->value());
    gravador.setMsg1(ui->edt_msg1->text());
    gravador.setMsg2(ui->edt_msg2->text());
    gravador.setTXServ(ui->edt_percServ->value());

    // db
    gravador.setFQDN(ui->edt_fqdn->text());
    gravador.setPorta(ui->edt_portbd->value());
    gravador.setUsuario(ui->edt_usuario->text());
    gravador.setSenha(ui->edt_senha->text());


    gravador.GravaArquivo(QDir::currentPath()+"/config2.xml");
}
