#ifndef PACMAN_H
#define PACMAN_H

#include "character.h"
#include "map.h"
#include <QTimer>

class Pacman : public Character
{
    Q_OBJECT

public:
    Pacman(Map *map_ipt);
    void setDirection (QPoint dire);

public slots:
    void move();
    void change();

private:
    QTimer *tmr;
    QPixmap pic[3];
    QPoint direction, tmp;
    Map *map;
};

#endif // PACMAN_H
