#pragma once

class Policeman : public Ant
{
    int growthFoodByPercent;
public:
    Policeman(int eat, int growth):Ant(eat),growthFoodByPercent(growth){}
    
    int getGrowth() const
    {
        return growthFoodByPercent;
    }
    void isDie() override
    {
        std::cout<<"Policeman is died.\n";
        delete this;
    }
};
