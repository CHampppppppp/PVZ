#include "footballzombie.h"

FootballZombie::FootballZombie()
{
    hp = 1670;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 2.5;
    setMovie(":/images/FootballZombieWalk.gif");//将一个movie指针指向zombie
}

void FootballZombie::advance(int phase)
{
    if (!phase)//????????
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)//state0 -> 行走  state1->攻击   state2->死亡
        {
            state = 2;//判定死亡
            setMovie(":/images/FootballZombieDie.gif");
            setHead(":/images/ZombieHead.gif");//僵尸头掉落

        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)//死亡gif播放完删除
            delete this;
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();//QGraphics中与footballzombie碰撞的items
    if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);//第一个与zombie碰撞的plant，转换成plant指针以修改plant_hp，如果碰撞的不是plant，该指针指向nullptr
        if(plant) plant->hp -= atk;
        if (state != 1)//state==0 
        {
            state = 1;
            setMovie(":/images/FootballZombieAttack.gif");//前movie指针存在，删掉并修改成播放攻击gif的指针
        }
        return;
    }
    if (state) //state==1
    {
        state = 0;
        setMovie(":/images/FootballZombieWalk.gif");
    }
    setX(x() - speed);
}
