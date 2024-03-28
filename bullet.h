#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>

class Bullet: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Bullet(QGraphicsTextItem *score=0);

public slots:
    void move();
private:
    int scoreValue;
    QGraphicsTextItem *score;
};

#endif // BULLET_H
