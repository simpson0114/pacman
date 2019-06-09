#include "game.h"
#include "pacman.h"
#include "map.h"
#include <QDebug>

Game::Game() {
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 448, 564);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(448, 564);
    setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/pic/map/map.png").scaledToWidth(448));
    dotNum = 240;
    pelletNum = 4;

    score = 0;
    scoreShow = new QGraphicsTextItem;
    scoreShow->setPlainText(QString::number(score));
    scoreShow->setPos(170, 0);
    scoreShow->setFont(QFont("", 20));
    scoreShow->setDefaultTextColor(Qt::white);
    scene->addItem(scoreShow);
    scoreShow->show();

    map = new Map();
    connect(map, SIGNAL(eat(QPoint)), this, SLOT(itemEat(QPoint)));

    QList<QPoint> dot;
    QList<QPoint> pellet;
    dot = map->setDot();
    pellet = map->setPellet();
    shine = new QTimer();
    for(int i = 0; i < dot.size(); i++) {
        item[dot[i].x()][dot[i].y()] = new Dot();
        item[dot[i].x()][dot[i].y()]->setPos(16 * dot[i].y(), 35 + 16 * dot[i].x());
        connect(item[dot[i].x()][dot[i].y()] , SIGNAL(dotEaten()), this, SLOT(ateDot()));
        scene->addItem(item[dot[i].x()][dot[i].y()]);
    }
    for(int i = 0; i < pellet.size(); i++) {
        item[pellet[i].x()][pellet[i].y()] = new Pellet();
        item[pellet[i].x()][pellet[i].y()]->setPos(16 * pellet[i].y(), 35 + 16 * pellet[i].x());
        connect(shine, SIGNAL(timeout()), item[pellet[i].x()][pellet[i].y()], SLOT(shine()));
        shine->start(150);
        connect(item[pellet[i].x()][pellet[i].y()] , SIGNAL(pelletEaten()), this, SLOT(atePellet()));
        scene->addItem(item[pellet[i].x()][pellet[i].y()]);
    }

    player = new Pacman(map);
    scene->addItem(player);
    player->setPos(216, 403);

    mv = new QTimer();
    connect(mv, SIGNAL(timeout()), player, SLOT(move()));
    mv->start(10);
    if(dotNum == 0)
        mv->stop();
    show();
}

void Game::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Up)
        player->setDirection(QPoint(0, -1));
    else if(event->key() == Qt::Key_Down)
        player->setDirection(QPoint(0, 1));
    else if(event->key() == Qt::Key_Left)
        player->setDirection(QPoint(-1, 0));
    else if(event->key() == Qt::Key_Right)
        player->setDirection(QPoint(1, 0));
}

void Game::itemEat(QPoint pos) {
    item[pos.x()][pos.y()]->eaten();
}


void Game::ateDot() {
    score += 10;
    scoreShow->setPlainText(QString::number(score));
    dotNum--;
}

void Game::atePellet() {
    score += 50;
    scoreShow->setPlainText(QString::number(score));
    pelletNum--;
}
