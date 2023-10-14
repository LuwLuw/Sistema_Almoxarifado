#include "devolucao.h"
#include "ui_devolucao.h"
QString Ran;
QString datt;
QString dir = "Arquivos_Almoxarifado";
QString past = "C:/";
QString mess;
QString mat;
QString no;
QString pr;

int quant =0;
 QSqlDatabase base = QSqlDatabase::database("ProfDB");
devolucao::devolucao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::devolucao)
{
    ui->setupUi(this);
}

devolucao::~devolucao()
{
    delete ui;
}

void devolucao::on_voltar_clicked()
{
    this->hide();
}

void devolucao::on_devolver_clicked()
{
    Ran = ui->RA_dev->text();
    int linha = ui->itens->currentRow();
    datt = ui->itens->item(linha,3)->text();
    mat = ui->itens->item(linha,4)->text();
    no = ui->itens->item(linha,0)->text();
    pr = ui->itens->item(linha,2)->text();

    QString name = Ran+"_"+datt+".txt";
    QString local = past + dir +"/";

    QFile arqu(local+name);
    if(!arqu.open(QFile::Append|QFile::Text)){
        QMessageBox::warning(this,"Erro","erro ao criar o arquivo");}
    QTextStream tex(&arqu);
    mess ="\ndevolvido";
    tex << mess;
    arqu.flush();
    arqu.close();
    QSqlQuery query(QSqlDatabase::database("ProfDB"));
    query.exec("update ped set dev = 'y' where Ra ='"+Ran+"' and Data ='"+datt+"' and Materiais ='"+mat+"' and Prof ='"+pr+"'");
    QMessageBox::about(this,"Devolução","Pedido marcado como devolvido");
    ui->itens->clear();
    ui->RA_dev->clear();
}


void devolucao::on_pesquisar_clicked()
{
   ui->itens->clear();
   Ran = ui->RA_dev->text();

   QSqlQuery query(QSqlDatabase::database("ProfDB"));
   if(query.exec("select Nome,Ra,Prof,Data,Materiais from ped where Ra = '"+Ran+"' and dev = 'n'")){
       while(query.next()){
           quant++;

       }
   }
   if(quant == 0){
       QMessageBox::about(this,"Erro ao ler banco de dados ","Não foram encontrados pedidos desse Ra no banco de dados,por favor verifique");
   }
   else{

       if(query.exec("select Nome,Ra,Prof,Data,Materiais from ped where Ra = '"+Ran+"' and dev = 'n'")){
           int cont =0;
           ui->itens->setColumnCount(5);
       while(query.next()){
          ui->itens->insertRow(cont);
          ui->itens->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
          ui->itens->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
          ui->itens->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
          ui->itens->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
          ui->itens->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));
         // ui->itens->setItem(cont,5,new QTableWidgetItem(query.value(5).toString()));
          ui->itens->setRowHeight(cont,20);

       }
       }
       QStringList cabecalhos ={"Nome","Ra","Professor","Data","Materiais"};
       ui->itens->setHorizontalHeaderLabels(cabecalhos);
       ui->itens->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->itens->setSelectionBehavior(QAbstractItemView::SelectRows);
       ui->itens->verticalHeader()->setVisible(false);
       ui->itens->setStyleSheet("QTableView {selection-background-color: white; selection-color:black}"
                                "QHeaderView::section{background-color:gray}");

}
}
