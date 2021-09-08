#include "widget.h"

#include <QApplication>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "splashscreen.h"
#include <QDesktopWidget>

QSqlQuery writeQuery;
QSqlQuery readQuery;

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::ApplicationAttribute::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    Widget w;

    SplashScreen splashScreen("");
    splashScreen.move((QApplication::desktop()->width() - splashScreen.width()) / 2 ,(QApplication::desktop()->height() - splashScreen.height()) / 2);
    splashScreen.show();
    a.processEvents();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if(db.open()){
        writeQuery = QSqlQuery(db);
        readQuery = QSqlQuery(db);
    }

    splashScreen.finish(&w);
    w.show();


    return a.exec();
}
