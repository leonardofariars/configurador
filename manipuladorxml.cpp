#include "manipuladorxml.h"
#include "stdio.h"
#include "iostream"
#include <QString>
#include <stdbool.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QXmlReader>
#include <QDebug>



#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif



ManipuladorXML::ManipuladorXML(const QString &Empresa, const QString &Telefone, const QString &CNPJ,
        const QString &End1, const QString &End2, const int &NMesas,
        const bool &CalcTX, const float &TXServ, const QString &TxtProm){

    vEmpresa = Empresa;
    vTelefone = Telefone;
    vCNPJ = CNPJ;
    vEnd1 = End1;
    vEnd2 = End2;
    vNMesas = NMesas;
    vCalcTX = CalcTX;
    vTXServ = TXServ;
    vTxtProm = TxtProm;
}

void ManipuladorXML::setEmpresa(const QString &Empresa){
    vEmpresa = Empresa;
}

void ManipuladorXML::setTelefone(const QString &Telefone){
    vTelefone = Telefone;
}

void ManipuladorXML::setCNPJ(const QString &CNPJ){
    vCNPJ = CNPJ;
}

void ManipuladorXML::setEnd1(const QString &End1){
    vEnd1 = End1;
}

void ManipuladorXML::setEnd2(const QString &End2){
    vEnd2 = End2;
}

void ManipuladorXML::setNMesas(const int &NMesas){
    vNMesas = NMesas;
}

void ManipuladorXML::setCalcTX(const bool &CalcTX){
    vCalcTX = CalcTX;
}

void ManipuladorXML::setTXServ(const float &TXServ){
    vTXServ = TXServ;
}

void ManipuladorXML::setTXProm(const QString &TxtProm){
    vTxtProm = TxtProm;
}

QString ManipuladorXML::getEmpresa(){
    return vEmpresa;
}

QString ManipuladorXML::getTelefone(){
return vTelefone;
}

QString ManipuladorXML::getCNPJ(){
    return vCNPJ;
}

QString ManipuladorXML::getEnd1(){
    return vEnd1;
}

QString ManipuladorXML::getEnd2(){
    return vEnd2;
}

int ManipuladorXML::getNMesas(){
    return vNMesas;
}

bool ManipuladorXML::getCalcTX(){
    return vCalcTX;
}

float ManipuladorXML::getTXServ(){
    return vTXServ;
}

QString ManipuladorXML::getTxtProm(){
    return vTxtProm;
}


void ManipuladorXML::GravaArquivo(){
    /*
    //QString caminho = GetCurrentDir;
    QString NomeDoArquivo =  "config.xml";
    QFile file(NomeDoArquivo);

    QDomDocument arquivo;
    arquivo.setContent(&file);

    QDomElement raiz = arquivo.firstChildElement();



    QString nomempresa = raiz.elementsByTagName("Empresa");


    QTextStream xout (&file);
    xout << arquivo.toString();
    file.flush();
    file.close();
    */
}


void ManipuladorXML::LeArquivo(QString arquivo){

    QFile arqXML(arquivo);

    if (! arqXML.open(QIODevice::ReadOnly | QIODevice::Text) ) {

//        QMessageBox::critical(this,"Erro de leitura",
//        "Ocorreu um problema ao abrir o arquivo XML com configurações da aplicação.");
                    return;
     }
    QXmlStreamReader xmlReader(&arqXML);

    // Faz um loop percorrendo cada elemento até que seja o fim do arquivo
    // ou encontre algum erro.

    while( !xmlReader.atEnd() && !xmlReader.hasError() ) {

        // Read next element
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        //If token is just StartDocument - go to next
        if( token == QXmlStreamReader::StartDocument ) {
            continue;
        }
        //If token is StartElement - read it
        if( token == QXmlStreamReader::StartElement ) {
            if( xmlReader.name() == "empresa" ) {
                continue;
            }
            QString valor = xmlReader.readElementText();
            if( xmlReader.name() == "nome" )
                setEmpresa(valor);

            if ( xmlReader.name() == "telefone")
                setTelefone(valor);

            if ( xmlReader.name() == "cnpj")
                setCNPJ(valor);
        }
        if (token == QXmlStreamReader::StartElement){
            if (xmlReader.name() == "atendimento"){

            }
        }
    }


    xmlReader.clear();
    arqXML.close();




}

