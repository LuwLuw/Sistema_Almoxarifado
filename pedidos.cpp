//adicionando bibliotecas
#include "pedidos.h"
#include "ui_pedidos.h"

#ifdef WINDOWS
   #include <direct.h>
   #define Define_CurrentDir _getcwd
#else
   #include <unistd.h>
   #define Define_CurrentDir getcwd
 #endif

//Declarando variaveis
QString nome;
QString valor;
QString Ra;
QString Materiais;
QString professor;
QString profmail;
QString mensagem;
QString mensag;
QString prof;
int op;
QString dire;
QString pasta;
int cont;
int quantidade = 0;
 QSqlDatabase sqlDatabase = QSqlDatabase::database("ProfDB");


//configuração da tela e banco de dados
Pedidos::Pedidos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pedidos)
{
     ui->setupUi(this);



    QSqlQuery query(QSqlDatabase::database("ProfDB"));
    if(query.exec("select * from Professores")){
        while(query.next()){
            quantidade++;

        }
    }
    if(quantidade == 0){
        QMessageBox::about(this,"Erro ao ler banco de dados ","Não foram encontrados professores no banco de dados,por favor verifique");
    }
    else{
        if(query.exec("select Nome from Professores")){
        while(query.next()){
            valor = query.value(0).toString();
            ui->Txt_professor->addItem(valor);
        }

        }
    }
}
Pedidos::~Pedidos()
{
    delete ui;
}



void Pedidos::on_limpar_clicked()//codigo do botão de limpar
{
    ui->Txt_nome->clear();
    ui->Txt_ra->clear();
    ui->Txt_materiais->clear();
    ui->Txt_nome->setFocus();
    ui->Txt_professor->setCurrentIndex(0);

}


void Pedidos::on_salvar_clicked()//codigo do botão de salvar
{
   //coletando dados
   nome = ui->Txt_nome->text();
   Ra = ui->Txt_ra->text();
   Materiais = ui ->Txt_materiais->toPlainText();
   professor = ui->Txt_professor->currentText();
   QDate dat = QDate::currentDate();
   QString data= dat.toString("dd-MM-yyyy");

   //apresentando os dados coletados
   QMessageBox::about(this,"Dados","Nome: "+nome+"\nRa: " +Ra+"\nProfessor: " +professor+"\nMateriais:\n " +Materiais);

   //limpando os dados da tela
   ui->Txt_nome->clear();
   ui->Txt_ra->clear();
   ui->Txt_materiais->clear();
   ui->Txt_nome->setFocus();

   //pegando o email do respectivo professor do banco de dados
   QSqlQuery query(QSqlDatabase::database("ProfDB"));
   if(query.exec("select email from Professores where Nome ='"+professor+"'")){
   while(query.next()){
       valor = query.value(0).toString();
       profmail = valor;
   }

   }
   //adicionando ao banco de dados
   if(query.exec("insert into ped (Nome,Ra,Prof,Data,Materiais,dev) values ('"+nome+"','"+Ra+"','"+professor+"','"+data+"','"+Materiais+"','n')")){
       QMessageBox::about(this,"Banco de Dados","Registro gravado com sucesso");
   }
   else{
       QMessageBox::about(this,"Banco de Dados","Erro ao adicionar no banco de dados");
   }

   //criando ou acessando a pasta de arquivos que serão salvos pelo sistema
   dire = "Arquivos_Almoxarifado";
   pasta = "C:/";

   QDir dir(pasta+dire);
   if(dir.exists()){
   //diretório ja existente
   }
   else{
       dir.mkdir(pasta+dire);
   }



   //gerando arquivo em pdf
   QString name = Ra+"_"+data+".txt";
   QString local = pasta + dire +"/";


   QFile arqu(local+name);
   if(arqu.open(QFile::ReadOnly|QFile::Text)){
   arqu.close();
   arqu.open(QFile::Append|QFile::Text);
   mensagem= "\n" +Materiais;
   QTextStream te(&arqu);
   te << mensagem;
   arqu.flush();
   arqu.close();
   }
   else{
   if(!arqu.open(QFile::WriteOnly|QFile::Text)){
       QMessageBox::warning(this,"Erro","erro ao criar o arquivo");}
   else{
   QTextStream tex(&arqu);
   mensagem ="From: Almoxarifado <almoxarifado.dee@gmail.com>\nTo: " +professor+ "<"+ profmail +">\nSubject: Pedido Almoxarifado\n\nNome: "+nome+"\nRa:"+Ra+"\nProfessor(a):"+professor+"\nPedido:\n" + Materiais;
   tex << mensagem;
   arqu.flush();
   arqu.close();
}
}
   //gerando arquivo em texto para envio do email
   QFile arquivo("email.txt");
   if(!arquivo.open(QFile::WriteOnly|QFile::Text)){
       QMessageBox::warning(this,"Erro","erro ao criar o arquivo email.txt");
   }
   QTextStream texto(&arquivo);
   mensagem ="From: Almoxarifado <almoxarifado.dee@gmail.com>\nTo: " +professor+ "<"+ profmail +">\nSubject: Pedido Almoxarifado\n\nNome: "+nome+"\nRa:"+Ra+"\nProfessor(a):"+professor+"\nPedido:\n" + Materiais;
   texto << mensagem;
   arquivo.flush();
   arquivo.close();


   //gerando arquivo que envia o email
   QFile arquiv("envio.bat");
   if(!arquiv.open(QFile::WriteOnly|QFile::Text)){
       QMessageBox::warning(this,"Erro","erro ao criar o arquivo email.txt");
   }
   QTextStream text(&arquiv);
   mensag ="curl --ssl-reqd smtps://smtp.gmail.com --mail-from almoxarifado.dee@gmail.com --mail-rcpt "+ profmail +" --user almoxarifado.dee@gmail.com:ouqcjvgslluerxwv --upload-file email.txt";
   text << mensag;
   arquiv.flush();
   arquiv.close();
   system("envio.bat");


}
void Pedidos::on_pushButton_clicked()
{
    this->hide();
}

