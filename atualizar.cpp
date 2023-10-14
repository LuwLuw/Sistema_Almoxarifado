#include "atualizar.h"
#include "ui_atualizar.h"

int quan =0;
QSqlDatabase bas = QSqlDatabase::database("ProfDB");
atualizar::atualizar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::atualizar)
{
    ui->setupUi(this);
}

atualizar::~atualizar()
{
    delete ui;
}

void atualizar::on_voltar_clicked()
{
    this->hide();
}


void atualizar::on_devolver_clicked()
{
    devol = new devolucao();
    devol -> show();
}


void atualizar::on_relatorio_clicked()
{
    QSqlQuery query(QSqlDatabase::database("ProfDB"));
    if(query.exec("select Nome,Ra,Prof,Data,Materiais from ped where dev = 'n'")){
        while(query.next()){
            quan++;

        }
    }
    if(quan == 0){
        QMessageBox::about(this,"Erro ao ler banco de dados ","Não foram encontrados pedidos desse Ra no banco de dados,por favor verifique");
    }
    else{

        if(query.exec("select Nome,Ra,Prof,Data,Materiais from ped where dev = 'n'")){
          QString txt;
          QString nam =QDir::currentPath()+ "/relatorio.pdf";
          QPrinter printer;
          int li =125;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName(nam);
          QPainter painter;
          painter.begin(&printer);
          painter.drawText(25,25,"Relatório de pedidos não devolvidos");
          painter.drawText(25,75,"Nome");
          painter.drawText(225,75,"Ra");
          painter.drawText(325,75,"Prof");
          painter.drawText(425,75,"Data");
          painter.drawText(525,75,"Materiais");
        while(query.next()){
            txt = query.value(0).toString();
            painter.drawText(25,li,txt);
            txt = query.value(1).toString();
            painter.drawText(225,li,txt);
            txt = query.value(2).toString();
            painter.drawText(325,li,txt);
            txt = query.value(3).toString();
            painter.drawText(425,li,txt);
            txt = query.value(4).toString();
            painter.drawText(525,li,txt);
            li = li + 50;

        }
        painter.end();
        system("relatorio.pdf");
        }
        }
}

