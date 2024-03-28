#include"bullet.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include "Score.h"
#include "main.h"



//extern Main * main;

Bullet::Bullet(QGraphicsTextItem * inScore) {
    score=inScore;
    scoreValue=0;
        // *******  Setting the bullets' size ********
    setPixmap(QPixmap(":/images/laser.jpeg").scaled(40, 40));

        // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(30);
}

//Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies
void Bullet:: move()
{
        // *******  Getting the colliding items with the Bullet ********
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int i=0;i<colliding_items.size();i++){
        if(typeid(*colliding_items[i])==typeid(Enemy)){
              scene()->removeItem(colliding_items[i]);
              // scoreValue++;
              // score->setPlainText(QString("Score: ") + QString::number(scoreValue));
              scene()->removeItem(this);
              delete this;
              delete colliding_items[i];
        }
    }
        // *******  Moving the bullets upward ********

    setPos(x(), y()-10);
             if (pos().y() < 0){
                 scene()->removeItem(this);
                 delete this;
         }
}

