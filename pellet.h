#ifndef PELLET_H
#define PELLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "item.h"

class Pellet: public Item {
    Q_OBJECT
public:
    Pellet();
    void eaten();
    bool visible;

public slots:
    void shine();

signals:
    void pelletEaten();
};

#endif // PELLET_H
