#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>


class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsTextItem * score = 0);
public:
    void keyPressEvent(QKeyEvent * event);

private:
    int scoreValue;
    QGraphicsTextItem * score;
public slots:
    void createEnemy();
     // void move();


};

#endif // PLAYER_H
