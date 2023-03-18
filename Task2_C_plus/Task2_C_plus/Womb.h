#pragma once

class Womb : public Ant
{
    int burnOfLarva;
public:
    Womb(int eat, int burnOfLarva):Ant(eat), burnOfLarva(burnOfLarva){}
    
    int getBurnOfLarva()
    {
        return burnOfLarva;
    }
    void isDie() override
    {
        std::cout<<"Womb is died.\n";
        delete this;
    }

    int typeOfAnt(int count)
    {
        switch (count%100)
        {
        case 0: {return 0;}
        case (1,25,50): {return 1;}
        }
        return count%100;
    }
};
