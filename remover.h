#ifndef REMOVER_H
#define REMOVER_H
#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
namespace Ui {
class remover;
}

class remover : public QWidget
{
    Q_OBJECT

public:
    explicit remover(QWidget *parent = nullptr);
    ~remover();

private slots:
    void on_rem_clicked();

    void on_pushButton_clicked();

private:
    Ui::remover *ui;
};

#endif // REMOVER_H
