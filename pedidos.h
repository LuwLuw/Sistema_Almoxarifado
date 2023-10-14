#ifndef PEDIDOS_H
#define PEDIDOS_H
#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <stdio.h>
#include <QApplication>
#include <QLocale>
#include <QTimer>
#include <QDate>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include "QPrinter"
#include "QPainter"
#include "QDebug"
#include "QDir"

namespace Ui {
class Pedidos;
}

class Pedidos : public QWidget
{
    Q_OBJECT

public:
    explicit Pedidos(QWidget *parent = nullptr);
    ~Pedidos();

private slots:


    void on_limpar_clicked();

    void on_salvar_clicked();

    void on_pushButton_clicked();

private:
    Ui::Pedidos *ui;
};

#endif // PEDIDOS_H
