#pragma once

class Worker :public Ant
{
private:
    int createEat;
public:
    Worker(int eat, int createEat):Ant(eat),createEat(createEat){}
    
    int getCreateEat()const{
        return createEat;
    }
    void isDie() override
    {
        std::cout<<"Worker is died.\n";
        delete this;
    }
};
