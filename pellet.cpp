#include "pellet.h"
#include <QObject>

Pellet::Pellet() {
    setPixmap(QPixmap(":/pic/item/pellet.png").scaledToWidth(16));
    visible = true;
}

void Pellet::eaten() {
    emit pelletEaten();
    delete this;
}

void Pellet::shine() {
    visible = !visible;
        if (visible)
            show();
        else
            hide();
}
