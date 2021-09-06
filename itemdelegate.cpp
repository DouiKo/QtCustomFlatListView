#include "itemdelegate.h"

#include <QPainter>
#include <QDebug>

ItemDelegate::ItemDelegate()
{

}

//QWidget *ItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{

//}

//void ItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
//{

//}

//void ItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
//{

//}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid())
    {
        painter->save();


        QVariant variant = index.data(Qt::UserRole + 1);
        GameItem gameData = variant.value<GameItem>();

        QRectF rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth(option.widget->width()-15);
        rect.setHeight(option.rect.height());

        //绘制每个item下边框
        QPen pen(QColor(68,68,68));
        pen.setWidthF(0.5);
        painter->setPen(pen);
        painter->drawLine(rect.left(),rect.bottom(),rect.right(),rect.bottom());

//        painter->drawRect(rect);
//        qDebug()<<rect;
        //响应鼠标状态
//        if(option.state.testFlag(QStyle::State_Selected)){
//            painter->setPen(QPen(Qt::blue));
//            painter->setBrush(QColor(229, 241, 255));
//            painter->drawPath(path);
//        }else if(option.state.testFlag(QStyle::State_MouseOver)){
//            painter->setPen(QPen(Qt::green));
//            painter->setBrush(Qt::NoBrush);
//            painter->drawPath(path);
//        }else{
//            painter->setPen(QPen(Qt::gray));
//            painter->setBrush(Qt::NoBrush);
//            painter->drawPath(path);
//        }
        //


        //绘制数据位置
        QRect imageRect = QRect(rect.left() +10,  rect.top() +4, 15, 15);
        QRect nameRect = QRect(rect.left()  +30,  rect.top() + painter->fontMetrics().height() / 2, 400, painter->fontMetrics().height());
        QRect tagsRect = QRect(rect.left()  +435, rect.top() + painter->fontMetrics().height() / 2, 200, painter->fontMetrics().height());
        QRect timeRect = QRect(rect.right() -70,  rect.top() + painter->fontMetrics().height() / 2, 70,  painter->fontMetrics().height());

        painter->setPen(QColor(68,68,68));
        painter->setFont(QFont("等线", 8));
        painter->drawText(nameRect,Qt::AlignLeft,gameData.getName());
//        painter->drawRect(nameRect);
        painter->drawText(tagsRect,Qt::AlignLeft,gameData.getTagsString());
//        painter->drawRect(tagsRect);
        painter->drawText(timeRect,Qt::AlignLeft,gameData.getTime());
//        painter->drawRect(timeRect);
        //可能需要使用线程优化性能
        painter->drawPixmap(imageRect,gameData.getIcon());

        painter->restore();
    }
}

QSize ItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(735, 30);
}
