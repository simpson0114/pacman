#include "dot.h"
#include <QObject>

Dot::Dot(){
    setPixmap(QPixmap(":/pic/item/dot.png").scaledToWidth(16));
}

void Dot::eaten() {
    emit dotEaten();
    delete this;
}

void Dot::shine() {

}
