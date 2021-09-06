#include "listviewpro.h"

#include <QEvent>

ListViewPro::ListViewPro(QWidget *parent) : QListView(parent)
{
}

ListViewPro::~ListViewPro()
{
}

void ListViewPro::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    emit mousePressPos(event->pos());
}

//void ListViewPro::mouseDoubleClickEvent(QMouseEvent *e)
//{
////    qDebug()<<e->pos();
//}

