#ifndef MANIPULADORXML_H
#define MANIPULADORXML_H


#include <QString>
#include <stdbool.h>
#include <QtXml>


class ManipuladorXML
{
public:
    ManipuladorXML(const QString &Empresa = "",const QString &Telefone = "",const QString &CNPJ = "",
                   const QString &End1 = "",const QString &End2 = "",const int &NMesas =1 ,
                   const bool &CalcTX = false,const float &TXServ = 0.0,const QString &TxtProm = "");

    // Grava os valores nas propriedades da classe

    void setEmpresa(const QString &Empresa);
    void setTelefone(const QString &Telefone);
    void setCNPJ(const QString &CNPJ);
    void setEnd1(const QString &End1);
    void setEnd2(const QString &End2);
    void setNMesas (const int &NMesas);
    void setCalcTX (const bool &CalcTX);
    void setTXServ (const float &TXServ);
    void setTXProm (const QString &TxtProm);

    // Lê os valores atribuidos a cada propriedade da classe

    QString getEmpresa();
    QString getTelefone();
    QString getCNPJ();
    QString getEnd1();
    QString getEnd2();
    int getNMesas();
    bool getCalcTX();
    float getTXServ();
    QString getTxtProm();

    // Manipulação do arquivo XML

    void GravaArquivo();
    void LeArquivo();
    void LeArquivo2();


private:
    QString vEmpresa;
    QString vTelefone;
    QString vCNPJ;
    QString vEnd1;
    QString vEnd2;
    int vNMesas;
    bool vCalcTX;
    float vTXServ;
    QString vTxtProm;
};

#endif // MANIPULADORXML_H
