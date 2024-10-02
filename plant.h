#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>

class Plant : public QGraphicsItem
{
public://便于与zombie交互
    int hp;
    int state;
    enum { Type = UserType + 1};//？
    Plant();
    ~Plant() override;
    QRectF boundingRect() const override;//返回占用面积
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;//判断碰撞
    int type() const override;
    void setMovie(QString path);
protected:
    QMovie *movie;
    int atk;
    int counter;
    int time;
};

#endif // PLANT_H
