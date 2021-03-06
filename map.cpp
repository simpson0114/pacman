#include "map.h"
#include <QDebug>

Map::Map() {
    initMap();
}

void Map::initMap() {
    map = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {-1, -1, -1, -1, -1, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {-1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 2, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 2, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
}

bool Map::canMove(QPointF pos, QPoint dire) {
    int i = int(pos.y() - 35) / 16;
    int j = int(pos.x()) / 16;
    if((pos.x() <= 0. && pos.y() == 259.) || (pos.x() >= 432. && pos.y() == 259.) || map[i + dire.y()][j + dire.x()])
        return true;
    else {
        return false;
    }
}

void Map::check(QPointF pos, QPoint dir) {
    int x = int(pos.y() - 35) / 16;
    int y = int(pos.x()) / 16;

    if (map[x][y] != 0 && map[x][y] != -1) {
        if (map[x][y] == 2)
            emit powerUp();
        map[x][y] = -1;
        emit eat(QPoint(x, y));
    }
    dir_player = dir;
}

QList<QPoint> Map::setDot() {
    QList<QPoint> dot;
    for(int i = 0; i < 31; i++) {
        for(int j = 0; j < 28; j++) {
            if(map[i][j] == 1 )
                dot.push_back(QPoint(i, j));
        }
    }
    return dot;
}

QList<QPoint> Map::setPellet() {
    QList<QPoint> pellet;
    for(int i = 0; i < 31; i++) {
        for(int j = 0; j < 28; j++) {
            if(map[i][j] == 2 )
                pellet.push_back(QPoint(i, j));
        }
    }
    return pellet;
}
