#ifndef DEVOLUCAO_H
#define DEVOLUCAO_H
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <qfile.h>
#include <QWidget>

namespace Ui {
class devolucao;
}

class devolucao : public QWidget
{
    Q_OBJECT

public:
    explicit devolucao(QWidget *parent = nullptr);
    ~devolucao();

private slots:
    void on_voltar_clicked();



    void on_devolver_clicked();

    void on_pesquisar_clicked();

private:
    Ui::devolucao *ui;
};

#endif // DEVOLUCAO_H
