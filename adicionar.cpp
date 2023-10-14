#include "adicionar.h"
#include "ui_adicionar.h"

QString name;
QString email;


adicionar::adicionar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adicionar)
{
    ui->setupUi(this);

}

adicionar::~adicionar()
{
    delete ui;
}

void adicionar::on_limpar_clicked()
{
    ui->Txt_nome->clear();
    ui->Txt_email->clear();
    ui->Txt_nome->setFocus();
}


void adicionar::on_add_clicked()
{
  name = ui->Txt_nome->text();
  email = ui->Txt_email->text();
  ui->Txt_nome->clear();
  ui->Txt_email->clear();
  ui->Txt_nome->setFocus();
  QSqlDatabase sqlDatabase = QSqlDatabase::database("ProfDB");
   QSqlQuery com(QSqlDatabase::database("ProfDB"));
   if(com.exec("insert into Professores (Nome,email) values ('"+name+"','"+email+"')")){
       QMessageBox::about(this,"Banco de Dados","Registro gravado com sucesso");
   }
   else{
       QMessageBox::about(this,"Banco de Dados","Erro ao adicionar no banco de dados");
   }

}



void adicionar::on_pushButton_clicked()
{
    this->hide();
}

