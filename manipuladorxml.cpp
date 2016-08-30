/* Leonardo de Oliveira Faria
 *
 *
 * Esta classe é responsável por armazenar os dados do arquivo XML
 * de configuração em suas propriedades. Ela busca o arquivo, que
 * deve estar no layout padrão da aplicação, e faz a leitura de
 * seus campos.
 * Para cada campo do arquivo, existe uma propriedade na clasee,
 * bem como métodos SET e GET, responsáveis por atribuir e ler
 * os valores dos mesmos.
 *
 *
 *
 *
 *
 *
 */

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
        const QString &End1, const QString &End2, const int &NMesas,const bool &CalcTX,
        const float &TXServ, const QString &Msg1, const QString &Msg2, const QString &fqdn,
        const int &Porta, const QString &Usuario, const QString &Senha){

    vEmpresa = Empresa;
    vTelefone = Telefone;
    vCNPJ = CNPJ;
    vEnd1 = End1;
    vEnd2 = End2;
    vNMesas = NMesas;
    vCalcTX = CalcTX;
    vTXServ = TXServ;
    vMsg1 = Msg1;
    vMsg1 = Msg2;
    vFQDN = fqdn;
    vPorta = Porta;
    vUsuario = Usuario;
    vSenha = Senha;
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

void ManipuladorXML::setMsg1(const QString &Msg1){
    vMsg1 = Msg1;
}

void ManipuladorXML::setMsg2(const QString &Msg2){
    vMsg2 = Msg2;
}

void ManipuladorXML::setFQDN(const QString &fqdn){
    vFQDN = fqdn;
}

void ManipuladorXML::setPorta(const int &Porta){
    vPorta = Porta;
}

void ManipuladorXML::setUsuario(const QString &Usuario){
    vUsuario = Usuario;
}

void ManipuladorXML::setSenha(const QString &Senha){
    vSenha = Senha;
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

QString ManipuladorXML::getMsg1(){
    return vMsg1;
}

QString ManipuladorXML::getMsg2(){
    return vMsg2;
}

QString ManipuladorXML::getFQDN(){
    return vFQDN;
}

int ManipuladorXML::getPorta(){
    return vPorta;
}

QString ManipuladorXML::getUsuario(){
    return vUsuario;
}

QString ManipuladorXML::getSenha(){
    return vSenha;
}

void ManipuladorXML::GravaArquivo(QString arquivo){
    QFile arqXML (arquivo);

    if (! arqXML.open(QIODevice::WriteOnly))
        return;

    QXmlStreamWriter xmlWriter(&arqXML);

    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("configuracoes");

    xmlWriter.writeStartElement("empresa");
        xmlWriter.writeTextElement("nome",getEmpresa());
        xmlWriter.writeTextElement("telefone",getTelefone());
        xmlWriter.writeTextElement("cnpj",getCNPJ());
        xmlWriter.writeTextElement("end1",getEnd1());
        xmlWriter.writeTextElement("end2",getEnd2());
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("atendimento");
        xmlWriter.writeTextElement("nmesas",QString::number(getNMesas()));
        xmlWriter.writeTextElement("msg1",getMsg1());
        xmlWriter.writeTextElement("msg2",getMsg2());
        //xmlWriter.writeTextElement("calcserv",getTXServ());
        //xmlWriter.writeAttribute()
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("db");
        xmlWriter.writeTextElement("fqdn",getFQDN());
        xmlWriter.writeTextElement("porta",QString::number(getPorta()));
        xmlWriter.writeTextElement("usuario",getUsuario());
        xmlWriter.writeTextElement("senha",getSenha());
    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();

    arqXML.close();
}




void ManipuladorXML::LeArquivo(QString arquivo){

    QFile arqXML(arquivo);

    // Se não for possível abrir o arquivo para leitura,
    // interrompe o processo.

    if (! arqXML.open(QIODevice::ReadOnly | QIODevice::Text) ) {

//        QMessageBox::critical(this,"Erro de leitura",
//        "Ocorreu um problema ao abrir o arquivo XML com configurações da aplicação.");
                    return;
     }

    QXmlStreamReader xmlReader(&arqXML);


    // Faz um loop percorrendo cada elemento até que seja o fim do arquivo
    // ou encontre algum erro.

    while( !xmlReader.atEnd() ) {

        xmlReader.readNext();

        if( xmlReader.name() == "empresa" || xmlReader.name() == "atendimento" || xmlReader.name() == "db" || xmlReader.name() == "configuracoes") {
            continue;
        }

        QString valor = xmlReader.readElementText();

        if( xmlReader.name() == "nome" )
            setEmpresa(valor);

        if ( xmlReader.name() == "telefone")
            setTelefone(valor);

        if ( xmlReader.name() == "cnpj")
            setCNPJ(valor);

        if ( xmlReader.name() == "end1")
            setEnd1(valor);

        if ( xmlReader.name() == "end2")
            setEnd2(valor);

        if( xmlReader.name() == "nmesas" )
            setNMesas(valor.toInt());

        if ( xmlReader.name() == "msg1" )
            setMsg1(valor);

        if ( xmlReader.name() == "msg2" )
            setMsg2(valor);

        if ( xmlReader.name() == "usuario")
            setUsuario(valor);

        if ( xmlReader.name() == "fqdn")
            setFQDN(valor);

        if ( xmlReader.name() == "porta")
            setPorta(valor.toInt());

        if ( xmlReader.name() == "senha")
            setSenha(valor);

            // Como o elemento calcserv possui um atributo,
            // sua leitura precisa ser um pouco diferente

        if ( xmlReader.name() == "calcserv" ){
            setTXServ(valor.toDouble());
            foreach (const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                QString natr = attr.name().toString();
                if (natr == "status"){
                    if (attr.value() == "true")
                        setTXServ(true);
                    else setTXServ(false);
                }
            }
        }

        continue;
    }

    xmlReader.clear();
    arqXML.close();

}

