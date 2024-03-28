
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QBrush>
#include <QMessageBox>
#include<QImage>
#include <QWidget>
#include <QColor>
#include "Score.h"
#include "health.h"
#include "main.h"

class GameLogic : public QObject {
    Q_OBJECT
public slots:

};
int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView view;
    view.setFixedSize(800, 600);
    //QBrush yellowBrush(Qt::yellow);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // *******  Create the Player ********
     Player *ship = new Player();
     // ship->setPixmap();
    // ship->setBrush(Qt::yellow);

    // ****** Create the Scene ********
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);
    scene.addItem(ship);
    scene.setBackgroundBrush(QBrush(QImage(":/images/background.jpeg")));

    // Score * s = new Score();
    // scene.addItem(s);

    // Health * h = new Health();
    // scene.addItem(h);
    // h->setPos(h->x(), h->y()+25);

    QGraphicsTextItem * score = new QGraphicsTextItem;
    score->setPlainText(QString("Score: ") + QString::number(0));
    score-> setDefaultTextColor(Qt::red);
    score->setFont(QFont("times",16));
    scene.addItem(score);
    score->setPos(700, 10);

    QGraphicsTextItem * health = new QGraphicsTextItem;
    health->setPlainText(QString("Health: ") + QString::number(3)); // Health: 3
    health-> setDefaultTextColor(Qt::red);
    health->setFont(QFont("times",16));
    scene.addItem(health);
    health->setPos(700, 40);




    // *******  Setting the foucs to the Player ********
    ship->setFlag(QGraphicsRectItem::ItemIsFocusable);
    ship->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********
    ship->setPos(view.width()/2, view.height() - ship->pixmap().height());

   // *******   Assign scene to the view   ***************
    view.setScene(&scene);
    view.show();

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),ship,SLOT(createEnemy()));
    time->start(2000);


    return a.exec();
}

