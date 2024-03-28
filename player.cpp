#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include "main.h"
#include <QGraphicsTextItem>
Player::Player(QGraphicsTextItem * inScore ){

    score=inScore;
    scoreValue=0;
    setPixmap(QPixmap(":/chickeninvaders1/ship.jpeg").scaled(90, 90));

}

void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * laser = new Bullet();
        laser->setPos(x()+30,y());
        scene()->addItem(laser);

    }


}
 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
  scene()->addItem(enemy);

}

//QGraphicsTextItem =
