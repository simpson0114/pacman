#ifndef ITEM_H
#define ITEM_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Item: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    virtual void eaten() = 0;
    virtual void shine() = 0;
};

#endif // ITEM_H
