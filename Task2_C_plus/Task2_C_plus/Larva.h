#pragma once
#include "Ant.h"

class Larva : public Ant
{
    int day;
public:
    Larva(int eat, int day):Ant(eat),day(day){}

    int getDay()
    {
        return day;
    }
    void setDay(int value)
    {
        day = value;
    }
    void isDie() override
    {
        std::cout<<"Larva is died.\n";
        delete this;
    }
    
    bool signalToWomb()
    {
        if (this->getDay()==3) return true;
        return false;
    }
}; 