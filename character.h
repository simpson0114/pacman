#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Character : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    virtual void move() = 0;
    virtual void setDirection (QPoint dire) = 0;
};

#endif // CHARACTER_H
