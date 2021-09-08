#include "splashscreen.h"
#include "ui_splashscreen.h"

#include <QFileDialog>
#include <QImageReader>
#include <QScrollBar>
#include"QtDebug"


SplashScreen::SplashScreen(QString filePath, QWidget *parent) :
    QSplashScreen(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::SplashScreen);

    this->layout()->setMargin(0);
    ui->label->setBackgroundRole(QPalette::Base);
    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label->setScaledContents(true);
    ui->label->adjustSize();

    QImageReader reader(":/i/SMEE_066.jpg");
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();

    ui->label->setPixmap(QPixmap::fromImage(newImage));





}

SplashScreen::~SplashScreen()
{
    delete ui;
}
