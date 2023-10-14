#include "tela_inicial.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Sistema_almoxarifado_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QSqlDatabase Professores_DB=QSqlDatabase::addDatabase("QSQLITE","ProfDB");
   QString dir = qApp->QCoreApplication::applicationDirPath();
    QString loc = dir + "/profdb.db";
    Professores_DB.setDatabaseName(loc);

    if(!Professores_DB.open()){

    }
    else{
    Tela_inicial w;
    w.show();
    return a.exec();
    }


}
