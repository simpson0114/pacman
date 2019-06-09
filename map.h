#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QGraphicsItem>
#include "dot.h"

class Map : public QObject {
    Q_OBJECT

public:
    Map();
    void initMap();
    void check(QPointF pos, QPoint dir);
    bool canMove(QPointF pos, QPoint dire);
    QList<QPoint> setDot();
    QList<QPoint> setPellet();

signals:
    void eat(QPoint pos);
    void powerUp();

private:
    QList<QList<int>> map;
    QPoint dir_player;
};

#endif // MAP_H
