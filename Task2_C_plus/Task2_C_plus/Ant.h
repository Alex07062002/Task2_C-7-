#pragma once

class Ant
{
    int eat;
public:
    Ant(int eat) : eat(eat){}
    virtual int getEat() const {
        return eat;
    }
    virtual void isDie(){}
    virtual ~Ant()
    {
    }
};
