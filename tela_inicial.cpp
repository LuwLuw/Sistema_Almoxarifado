#include "tela_inicial.h"
#include "ui_tela_inicial.h"

//QSqlDatabase Professores_DB=QSqlDatabase::addDatabase("QSQLITE","ProfDB");
//QString dir = QCoreApplication::applicationDirPath();
//QString loc = dir + "/profdb.db";

Tela_inicial::Tela_inicial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tela_inicial)
{
    ui->setupUi(this);

    //Professores_DB.setDatabaseName(loc);
    //Professores_DB.open();
}

Tela_inicial::~Tela_inicial()
{
    delete ui;
}


void Tela_inicial::on_pedido_clicked()
{
    Pedido = new Pedidos();
    Pedido->show();
}


void Tela_inicial::on_sair_clicked()
{
    close();
}


void Tela_inicial::on_adicionar_clicked()
{
    add = new adicionar();
    add->show();
}



void Tela_inicial::on_remov_clicked()
{
    remove = new remover();
    remove->show();
}


void Tela_inicial::on_att_pedido_clicked()
{
    att = new atualizar();
    att ->show();
}

