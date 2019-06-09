#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include "character.h"
#include "map.h"
#include "item.h"
#include "dot.h"
#include "pellet.h"

class Game: public QGraphicsView {
    Q_OBJECT
public:
    Game();
    void keyPressEvent(QKeyEvent *event);

public slots:
    void ateDot();
    void atePellet();
    void itemEat(QPoint pos);

private:
    int dotNum, pelletNum, score;
    QGraphicsTextItem *scoreShow;
    QGraphicsScene *scene;
    Character *player;
    Map *map;
    QTimer *mv;
    QTimer *shine;
    Item *item[31][28];
};

#endif // GAME_H
