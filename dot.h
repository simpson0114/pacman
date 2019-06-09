#ifndef DOT_H
#define DOT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "item.h"


class Dot: public Item {
    Q_OBJECT
public:
    Dot();
    void eaten();
    void shine();
signals:
    void dotEaten();
};

#endif // DOT_H
