#include "gameitem.h"

#include <QFileIconProvider>
#include <qfileinfo.h>
#include <QtDebug>

GameItem::GameItem()
{

}

GameItem::~GameItem()
{

}

QString GameItem::getName() const
{
    return name;
}

void GameItem::setName(const QString &value)
{
    name = value;
}

QString GameItem::getTime() const
{
    return time;
}

void GameItem::setTime(const QString &value)
{
    time = value;
}

QStringList GameItem::getTagList() const
{
    return tagList;
}

void GameItem::insertTagToList(const QString &tag)
{
    tagList.append(tag);
}

void GameItem::setTagList(const QStringList &value)
{
    tagList = value;
}

QString GameItem::getTagsString() const
{
    QString tags = "";
    foreach (auto var, tagList) {
        if(!tags.isEmpty())tags.append("/");
        tags.append(var);
    }
    return tags;
}

QPixmap GameItem::getIcon() const
{
    QFileInfo fileInfo(filePath);
    QFileIconProvider seekIcon;
    QIcon icon = seekIcon.icon(fileInfo);
    QPixmap pixmap=icon.pixmap(QSize(32,32));
    return pixmap;
}

QString GameItem::getFilePath() const
{
    return filePath;
}

void GameItem::setFilePath(const QString &value)
{
    filePath = value;
}

bool GameItem::isDataChanged() const
{
    return dataChanged;
}

void GameItem::setDataChanged(bool value)
{
    dataChanged = value;
}

