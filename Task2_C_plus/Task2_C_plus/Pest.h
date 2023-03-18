#pragma once

class Pest
{
    int eat;
    int soldierIsDie;
public:
    Pest(int eat,int soldierIsDie):eat(eat),soldierIsDie(soldierIsDie){}

    int getEat() const
    {
        return eat;
    }
    int getSoldierIsDie() const
    {
        return soldierIsDie;
    }
    void isDie() const
    {
        std::cout<<"Pest is died.\n";
        delete this;
    }
};
