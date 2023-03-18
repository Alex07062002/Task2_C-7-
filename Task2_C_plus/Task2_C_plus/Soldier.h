#pragma once

class Soldier : public Ant
{
    int pestIsDie;
public:
    Soldier(int eat,int pestIsDie):Ant(eat),pestIsDie(pestIsDie){}
    
    int getPestIsDie()
    {
        return pestIsDie;
    }
    void isDie() override
    {
        std::cout<<"Soldier is died.\n";
        delete this;
    }
};
