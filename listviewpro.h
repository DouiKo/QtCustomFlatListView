#ifndef LISTVIEWPRO_H
#define LISTVIEWPRO_H

#include <QListView>
#include <QDebug>
#include <QWidget>
#include <QMouseEvent>

class ListViewPro : public QListView
{
    Q_OBJECT
public:
    ListViewPro(QWidget *parent = nullptr);
    ~ListViewPro();
    void mousePressEvent(QMouseEvent *event) override;
//    void mouseDoubleClickEvent(QMouseEvent *e) override;
signals:
    void mousePressPos(QPoint point);
};

#endif // LISTVIEWPRO_H
