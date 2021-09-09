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

    createListViewMenu();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onMousePressPos(QPoint point)
{
    QRect rect = ui->listView->visualRect(ui->listView->currentIndex());
}

void Widget::initGameData()
{
    listModel = new QStandardItemModel(this);

    for (int i = 0; i < 500; ++i) {
        QStandardItem *item = new QStandardItem();
        GameItem game;
        game.setName("千恋万花" + QString::number(i));
        game.setTime("09/05 22:26");
        game.insertTagToList("纯爱");
        game.insertTagToList("日常");
        game.insertTagToList("柚子");
        game.setFilePath("C:/Users/29856/AppData/Local/GitHubDesktop/GitHubDesktop.exe");
        QVariant variant = QVariant::fromValue(game);
        item->setData(variant,Qt::UserRole+1);
        listModel->appendRow(item);
    }
}

void Widget::createListViewMenu()
{
    ui->listView->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    connect(ui->listView,&QListView::customContextMenuRequested,this,&Widget::onListViewMenuRequested);
    listViewMenu = new QMenu(this);

    startAction = new QAction(this);
    startAction->setText("启动");
    //slot
    listViewMenu->addAction(startAction);

    showViewAction = new QAction(this);
    showViewAction->setText("详细信息");
    //slot
    listViewMenu->addAction(showViewAction);

    settingAction = new QAction(this);
    settingAction->setText("游戏设置");
    //slot
    listViewMenu->addAction(settingAction);


    listViewMenu->addSeparator();
    deleteAction = new QAction(this);
    deleteAction->setText("删除游戏");
    //slot
    listViewMenu->addAction(deleteAction);
}

void Widget::on_listView_doubleClicked(const QModelIndex &index)
{
    QVariant variant = ui->listView->currentIndex().data(Qt::UserRole + 1);
    GameItem gameData = variant.value<GameItem>();
    qDebug()<<gameData.getName();
}

void Widget::onListViewMenuRequested(const QPoint point)
{
    if(ui->listView->indexAt(point).isValid()){
        listViewMenu->exec(QCursor::pos());
    }
}
