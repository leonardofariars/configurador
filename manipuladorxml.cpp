#include "manipuladorxml.h"
#include "stdio.h"
#include "iostream"
#include <QString>
#include <stdbool.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "tinyxml2.h"
#include <QXmlReader>



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

void ManipuladorXML::LeArquivo(){
    QString NomeDoArquivo =  "c:/config.xml";
    QFile file(NomeDoArquivo);

    if (! file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QByteArray dadosXML(file.readAll());

    QDomDocument arquivo;

    arquivo.setContent(dadosXML);

    // Seta o root do documento
/*

    QDomElement raiz = arquivo.firstChildElement();
    QDomText texto;

    texto = raiz.


    QDomNodeList nosfilhos = raiz.childNodes();
    QDomNode noatual;

    arquivo.TextNode

    for (int i = 0; i< nosfilhos.count(); i++){
        noatual = nosfilhos.at(i);
        QDomElement elemento;
        QDomNode = na;
        na.

        if ( noatual.isElement() ){
            elemento = noatual.toElement();

            QString nmno = elemento.nodeName();
            QString vlno = elemento.nodeValue();
            QDomText txt = elemento.toText();




            QString txno = txt.data();
            QString atr = elemento.   attribute("nn");
        }
    }





    QDomNodeList nos = raiz.elementsByTagName(raiz.nodeName());
    QDomElement elemento;

    for (int i = 0; i< nos.count(); i++){// percorre os nós filhos
        elemento = nos.at(i);
        if (no.isElement()){ // se for elemento verifica qual e grava na classe.
            QDomElement elemento = no.toElement();
            QString nomeEl = elemento.nodeName();
            nomeEl = nomeEl.toUpper();
                if (nomeEl == "NOME" ) setEmpresa(elemento.text());
                    else if (nomeEl == "TELEFONE") setTelefone(elemento.text());
                         else if (nomeEl == "CNPJ") setCNPJ(elemento.text());
             }
    }


    if (no.isElement()) // se for elemento grava na classe.
        setEmpresa(elemento.text());
    else setEmpresa("");

    nos = raiz.elementsByTagName("telefone");
    no = nos.at(0);
    if (no.isElement()) // se for elemento grava na classe.
        setTelefone(elemento.text());
    else setTelefone("");

    nos = raiz.elementsByTagName("cnpj");
    no = nos.at(0);
    if (no.isElement()) // se for elemento grava na classe.
        setCNPJ(elemento.text());
    else setCNPJ("");*/



}

void ManipuladorXML::LeArquivo2(){
    QXmlStreamReader xmlReader;

    QString NomeDoArquivo =  "c:/config.xml";
    QFile file(NomeDoArquivo);

    if (! file.open(QIODevice::ReadOnly | QIODevice::Text)){
            return;
    }

    xmlReader.setDevice(&file);
    xmlReader.readNext();

    while (! xmlReader.atEnd()){

        if (xmlReader.name() == "nome"){
            QString nmempresa = xmlReader.readElementText();
            setEmpresa(nmempresa);
        } else xmlReader.readNext();

    }



}

