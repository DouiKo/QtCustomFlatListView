#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QStandardItem>
#include "gameitem.h"
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void onMousePressPos(QPoint point);

    void on_listView_doubleClicked(const QModelIndex &index);

    void onListViewMenuRequested(const QPoint point);

private:
    void initGameData();

    void createListViewMenu();

private:
    QMenu *listViewMenu;
    QAction *settingAction;
    QAction *deleteAction;
    QAction *showViewAction;
    QAction *startAction;
    QStandardItemModel *listModel;
    Ui::Widget *ui;
};
#endif // WIDGET_H
