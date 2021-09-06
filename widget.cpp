#include "widget.h"
#include "ui_widget.h"
#include <QScrollBar>
#include "itemdelegate.h"
#include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initGameData();

    ui->listView->setItemDelegate(new ItemDelegate());
    ui->listView->setModel(listModel);
    ui->listView->setViewMode(QListView::IconMode);
    ui->listView->setSpacing(5);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::initGameData()
{
    listModel = new QStandardItemModel(this);

    for (int i = 0; i < 500; ++i) {
        QStandardItem *item = new QStandardItem();
        GameItem game;
        game.setName("这里是标题" + QString::number(i));
        game.setTime("09/05 22:26");
        game.insertTagToList("标签1");
        game.insertTagToList("标签2");
        game.setFilePath("C:/Users/29856/AppData/Local/GitHubDesktop/GitHubDesktop.exe");
        QVariant variant = QVariant::fromValue(game);
        item->setData(variant,Qt::UserRole+1);
        listModel->appendRow(item);
    }

}

