#ifndef GHOST_H
#define GHOST_H

#include "character.h"
#include "map.h"
#include <QTimer>

class Ghost : public Character {
    Q_OBJECT

public:
    Ghost(Map *map_ipt);
    void setDirection (QPoint dire);

public slots:
    void move();
    void change();

private:
    QTimer *tmr;
    QPixmap pic[2];
    QPoint direction, tmp;
    Map *map;
};

#endif // GHOST_H
