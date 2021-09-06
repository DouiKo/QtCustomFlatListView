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
    ui->listView->setDragEnabled(false);
    ui->listView->setEditTriggers(QListView::NoEditTriggers);
    connect(ui->listView,&ListViewPro::mousePressPos,this,&Widget::onMousePressPos);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onMousePressPos(QPoint point)
{
    QRect rect = ui->listView->visualRect(ui->listView->currentIndex());
    if(point.x() > 373 && point.x() < 391 && point.y() > rect.y() + 9 && point.y() < rect.y() + rect.height() - 9){
        qDebug()<<"clicked button1";
    }
    if(point.x() > 396 && point.x() < 414 && point.y() > rect.y() + 9 && point.y() < rect.y() + rect.height() - 9){
        qDebug()<<"clicked button2";
    }
}

void Widget::initGameData()
{
    listModel = new QStandardItemModel(this);

    for (int i = 0; i < 10; ++i) {
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

void Widget::on_listView_clicked(const QModelIndex &index)
{
//    QVariant variant = ui->listView->currentIndex().data(Qt::UserRole + 1);
//    GameItem gameData = variant.value<GameItem>();
//    qDebug()<<gameData.getName();
//    qDebug()<<ui->listView->visualRect(index);
}
