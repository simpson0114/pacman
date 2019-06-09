#include "pacman.h"
#include <QDebug>

Pacman::Pacman(Map *map_ipt) : map(map_ipt) {
    tmr = new QTimer();
    connect(tmr, SIGNAL(timeout()), this, SLOT(change()));
    tmr->start(100);
    for(int i = 0; i < 3; i++) {
        pic[i].load(":/pic/pacman/" + QString::number(i) + ".png");
        pic[i] = pic[i].scaledToHeight(30);
    }
    setPixmap(pic[0]);
    setOffset(-7, -7);
    direction = QPoint(1, 0);
    setTransformOriginPoint(boundingRect().width()/2-7,boundingRect().height()/2-7);
}

void Pacman::change() {
    static int index = 0, add = 1;
//    qDebug() << index;
    setPixmap(pic[index]);
    index += add;
    if(index >= 2 || index <= 0)
        add = -add;
    if(direction == QPoint(0, -1))
        setRotation(270);
    else if (direction == QPoint(0, 1))
        setRotation(90);
    else if (direction == QPoint(-1, 0))
        setRotation(180);
    else if (direction == QPoint(1, 0))
        setRotation(0);
}

void Pacman::move() {
    qDebug() << pos();
    map->check(pos(), direction);
    if(y() == 259. && (x() < 0 || x() >= 448)) {
        if (tmp == QPoint(-1, 0) || tmp == QPoint(1, 0))
            direction = tmp;
        setPos(pos() + direction * 2);

        if (x() < -30)
            setX(478);
        else if (x() > 478)
            setX(-30);
    }
    else if(int(y()-35) % 16 == 0 && int(x()) % 16 == 0) {
//        qDebug() << pos();
        if(map->canMove(pos(), tmp)) {
            direction = tmp;
            setPos(pos() + direction);
        }
        else if (map->canMove(pos(), direction))
            setPos(pos() + direction);
    }
    else
        setPos(pos() + direction);
}

void Pacman::setDirection(QPoint dire) {
    tmp = dire;
}
