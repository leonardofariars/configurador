#include "configwindow.h"
#include "ui_configwindow.h"
#include "limits.h"
#include "simplecrypt.h"


#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>

ConfigWindow::ConfigWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigWindow)

{
    ui->setupUi(this);
    Banco = QSqlDatabase::addDatabase("QMYSQL");

    ManipuladorXML leitor;

    QString narq;
    narq = QDir::currentPath() + "/config.xml";



    if (leitor.LeArquivo(narq)){

        ui->edt_nmempresa->setText(leitor.getEmpresa());
        ui->edt_cnpj->setText(leitor.getCNPJ());
        ui->edt_fnemp->setText(leitor.getTelefone());
        ui->edt_end1->setText(leitor.getEnd1());
        ui->edt_end2->setText(leitor.getEnd2());
        ui->chk_calcServ->setChecked(leitor.getCalcTX());
        ui->edt_percServ->setText(QString::number(leitor.getTXServ()));
        ui->edt_numMesa->setText(QString::number(leitor.getNMesas()));
        ui->edt_msg1->setText(leitor.getMsg1());
        ui->edt_msg2->setText(leitor.getMsg2());
        ui->edt_fqdn->setText(leitor.getFQDN());
        ui->edt_portdb->setText(QString::number(leitor.getPorta()));
        ui->edt_usuario->setText(leitor.getUsuario());
        ui->edt_senha->setText( Descriptografa( leitor.getSenha() ) );

    }

    else {
        QMessageBox::critical(this,"Erro ao abrir arquivo",
    "Ocorreu um erro abrir o arquivo de configurações da aplicação.");
        close();
    }




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

QString ConfigWindow::Criptografa(QString Texto){
    SimpleCrypt s;
    s.setKey(19820806);
    return s.encryptToString(Texto);
}

QString ConfigWindow::Descriptografa(QString Texto){
    SimpleCrypt s;
    s.setKey(19820806);
    return s.decryptToString(Texto);
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

void ConfigWindow::on_btn_grava_clicked(){

    ManipuladorXML gravador;
    // Empresa
    gravador.setEmpresa(ui->edt_nmempresa->text());
    gravador.setTelefone(ui->edt_fnemp->text());
    gravador.setCNPJ(ui->edt_cnpj->text());
    gravador.setEnd1(ui->edt_end1->text());
    gravador.setEnd2(ui->edt_end2->text());

    // Atendimento
    gravador.setNMesas(ui->edt_numMesa->text().toInt());
    gravador.setMsg1(ui->edt_msg1->text());
    gravador.setMsg2(ui->edt_msg2->text());
    gravador.setTXServ(ui->edt_percServ->text().toFloat());

    // db
    gravador.setFQDN(ui->edt_fqdn->text());
    gravador.setPorta(ui->edt_portdb->text().toInt());
    gravador.setUsuario(ui->edt_usuario->text());
    gravador.setSenha(Criptografa( ui->edt_senha->text() ) );


    gravador.GravaArquivo(QDir::currentPath()+"/config.xml");
    close();
}

void ConfigWindow::on_btn_tstcon_clicked(){
    Banco.setHostName( ui->edt_fqdn->text() );
    Banco.setPort( ui->edt_portdb->text().toInt() );
    Banco.setUserName( ui->edt_usuario->text() );
    Banco.setPassword( ui->edt_senha->text());
    Banco.setDatabaseName( ui->edt_instancia->text() );
    if (Banco.open()) {
        //banco conectou
    }
    else {
        }// banco nao conectou

}
