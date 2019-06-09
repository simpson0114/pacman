#include "ghost.h"

Ghost::Ghost(Map *map_ipt) : map(map_ipt) {
    tmr = new QTimer();
    connect(tmr, SIGNAL(timeout()), this, SLOT(change()));
    tmr->start(100);
    for(int i = 0; i < 2; i++) {
        pic[i].load(":/pic/pacman/" + QString::number(i) + ".png");
        pic[i] = pic[i].scaledToHeight(30);
    }
    setPixmap(pic[0]);
    setOffset(-7, -7);
    direction = QPoint(1, 0);
    setTransformOriginPoint(boundingRect().width()/2-7,boundingRect().height()/2-7);
}
