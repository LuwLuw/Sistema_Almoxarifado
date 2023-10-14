#include "remover.h"
#include "ui_remover.h"

QString selec;
QString val;
int quanti =0;
QSqlDatabase banco = QSqlDatabase::database("ProfDB");

remover::remover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::remover)
{
    ui->setupUi(this);
    QSqlQuery query(QSqlDatabase::database("ProfDB"));
    if(query.exec("select * from Professores")){
        while(query.next()){
            quanti++;

        }
    }
    if(quanti == 0){
        QMessageBox::about(this,"Erro ao ler banco de dados ","Não foram encontrados professores no banco de dados,por favor verifique");
    }
    else{
        if(query.exec("select Nome from Professores")){
        while(query.next()){
            val = query.value(0).toString();
            ui->prof->addItem(val);
        }

        }
    }
}


        remover::~remover()
{
    delete ui;
}

void remover::on_rem_clicked()
{
    selec = ui->prof->currentText();
    QSqlQuery re(QSqlDatabase::database("ProfDB"));
    if(re.exec("delete from Professores where Nome ='"+selec+"'")){
        QMessageBox::about(this,"Banco de Dados","Registro deletado com sucesso");
    }
    else{
        QMessageBox::about(this,"Banco de dados","Erro ao apagar registro");
    }
    ui->prof->setCurrentIndex(0);
}


void remover::on_pushButton_clicked()
{
    this->hide();
}

