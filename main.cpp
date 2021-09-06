#include "widget.h"

#include <QApplication>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

QSqlQuery writeQuery;
QSqlQuery readQuery;

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::ApplicationAttribute::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if(db.open()){
        writeQuery = QSqlQuery(db);
        readQuery = QSqlQuery(db);
    }

    Widget w;
    w.show();

    return a.exec();
}
