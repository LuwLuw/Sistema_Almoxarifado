#ifndef ADICIONAR_H
#define ADICIONAR_H
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
namespace Ui {
class adicionar;
}

class adicionar : public QDialog
{
    Q_OBJECT

public:
    explicit adicionar(QWidget *parent = nullptr);
    ~adicionar();

private slots:
    void on_limpar_clicked();

    void on_add_clicked();

    void on_pushButton_clicked();

private:
    Ui::adicionar *ui;
};

#endif // ADICIONAR_H
