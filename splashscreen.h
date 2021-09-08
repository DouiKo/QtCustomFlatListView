#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QWidget>
#include <QLayout>
#include <QSplashScreen>
#include <QLabel>
#include <QScrollArea>
#include <QMainWindow>
#include <QDialog>

namespace Ui {
class SplashScreen;
}

class SplashScreen : public QSplashScreen  //QMainWindow的setScaledContent方法无效
{
    Q_OBJECT

public:
    explicit SplashScreen(QString filePath,QWidget *parent = nullptr);
    ~SplashScreen();

private:
    Ui::SplashScreen *ui;
};

#endif // SPLASHSCREEN_H
