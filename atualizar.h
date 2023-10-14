#ifndef ATUALIZAR_H
#define ATUALIZAR_H
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QWidget>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QDir>
#include "devolucao.h"

namespace Ui {
class atualizar;
}

class atualizar : public QWidget
{
    Q_OBJECT

public:
    explicit atualizar(QWidget *parent = nullptr);
    ~atualizar();

private slots:
    void on_voltar_clicked();

    void on_devolver_clicked();

    void on_relatorio_clicked();

private:
    Ui::atualizar *ui;
    devolucao *devol;
};

#endif // ATUALIZAR_H
