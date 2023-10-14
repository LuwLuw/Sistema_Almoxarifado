#ifndef TELA_INICIAL_H
#define TELA_INICIAL_H
#include "pedidos.h"
#include "adicionar.h"
#include "remover.h"
#include "atualizar.h"
#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QApplication>
QT_BEGIN_NAMESPACE
namespace Ui { class Tela_inicial; }
QT_END_NAMESPACE

class Tela_inicial : public QMainWindow
{
    Q_OBJECT

public:
    Tela_inicial(QWidget *parent = nullptr);
    ~Tela_inicial();

private slots:


    void on_pedido_clicked();

    void on_sair_clicked();

    void on_adicionar_clicked();

    void on_remov_clicked();

    void on_att_pedido_clicked();

private:
    Ui::Tela_inicial *ui;
    Pedidos * Pedido;
    adicionar *add;
    remover *remove;
    atualizar *att;

};
#endif // TELA_INICIAL_H
