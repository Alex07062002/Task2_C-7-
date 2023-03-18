#pragma once
#include <iostream>

#include "Larva.h"
#include "Policeman.h"
#include "Soldier.h"
#include "Womb.h"
#include "Worker.h"
#include "Pest.h"


static constexpr  int eatsWomb = 10 ;
static constexpr  int eatSoldier = 5;
static constexpr  int eatPolicemen = 3;
static constexpr  int eatWorker = 1;
static constexpr  int eatLarva = 3;
static constexpr  int burnLarva = 7;
static constexpr  int dieOfPest = 2;
static constexpr  int growthCreateEatByPercent = 3;
static constexpr  int createEat = 5;

class Anthill
{
    double wareHouseOfEatSize;
    double startEat;
    Womb* WombSingle;
    std::vector<Soldier*> numOfSoldiers;
    std::vector<Policeman*> numOfPoliceman;
    std::vector<Worker*> numOfWorkers;
    std::vector<Larva*> numOfLarva;
public:
Anthill(double wareHouseOfEatSize,double startEat, int numOfSoldiers, int numOfPoliceman, int numOfWorkers)
{
    this->wareHouseOfEatSize = wareHouseOfEatSize;
    this->startEat = startEat;
    this->WombSingle = new Womb(eatsWomb,burnLarva);
    this-> numOfSoldiers = std::vector<Soldier*>();
    SetSoldierList(numOfSoldiers);
    this-> numOfPoliceman = std::vector<Policeman*>();
    SetPolicemanList(numOfPoliceman);
    this-> numOfWorkers = std::vector<Worker*>();
    SetWorkerList(numOfWorkers);
    this->numOfLarva = std::vector<Larva*>();
}
    void eatWomb()
{
        if (startEat>=WombSingle->getEat())
        {
            startEat -= WombSingle->getEat();
        }
        else
        {
            WombSingle->isDie();
        }
}
    void createLarva()
{
for(int i=0; i<WombSingle->getBurnOfLarva();i++)
{
    addToLarvaList(new Larva(eatLarva,0));
    std::cout<<"Larva is created.\n";
}
}
    void WombIsDie() const
{
    this->WombSingle->isDie();
}

    void SetSoldierList(unsigned int num)
{
    for (unsigned int i = 0; i < num;i++)
    {
        AddToSoldierList(new Soldier(eatSoldier,dieOfPest)); 
    }
}
    void AddToSoldierList(Soldier *ant)
{
 this->numOfSoldiers.push_back(ant);   
}
void isCareAnthill(std::vector<Pest*>pests)
{
        int sumSoldier = 0;
        int sumPest = 0;
        for (const auto element: pests)
        {
        sumSoldier += element->getSoldierIsDie();
        }
        if (sumSoldier>=static_cast<int>(numOfSoldiers.size()))
        {
            numOfSoldiers.clear();
            std::cout<<"All soldiers are died.\n";
            numOfPoliceman.clear();
            numOfWorkers.clear();
            numOfLarva.clear();
            WombIsDie();
        }
        else
        {
            for (int i = 0; i<sumSoldier;i++)
            {
                numOfSoldiers.erase(numOfSoldiers.end(),numOfSoldiers.end());
                std::cout<<"Soldier is died.\n";
            }
        }
        for (const auto element : numOfSoldiers)
        {
            sumPest += element->getPestIsDie(); }
        if (sumPest>=static_cast<int>(pests.size()))
        {
            pests.clear();
            std::cout<<"All pests are died.\n";

        }
        else
        {
            for (int i = 0; i<sumPest;i++)
            {
                pests.erase(pests.end(),pests.end());
                std::cout<<"Pest is died.\n";

            }
        }
}
    void eatSoldiers()
{
    for (int i = 0; i<numOfSoldiers.size()-1;i++)
    {
        if (startEat>=numOfSoldiers[i]->getEat())
        {
            startEat -= numOfSoldiers[i]->getEat();
            std::cout<<"Soldier is eating.\n";
        }
        else
        {
            numOfSoldiers.erase(numOfSoldiers.begin()+i,numOfSoldiers.begin()+i);
            std::cout<<"Soldier is died.\n";
        }
    }
}
    void SoldierIsDie() const
{
    numOfSoldiers[numOfSoldiers.size()-1]->isDie();
}
    void SetPolicemanList(unsigned int num)
{
    for (unsigned int i = 0; i<num;i++)
    {
        AddToPolicemanList(new Policeman(eatPolicemen,growthCreateEatByPercent));
    }
}
    void AddToPolicemanList(Policeman* ant)
{
    this->numOfPoliceman.push_back(ant);   
}
    double growthByPercent() const
{
    double multiplier = 1;
    for (const auto element : numOfPoliceman)
    {
        multiplier *= (1+(element->getGrowth()/100.0));
    }
    return multiplier;
}
    void eatPoliceman()
{
    for(int i = 0; i<numOfPoliceman.size();i++)
    {
        if (startEat>=numOfPoliceman[i]->getEat())
        {
            startEat -= numOfPoliceman[i]->getEat();
            std::cout<<"Policeman is eating.\n";

        }
        else
        {
            numOfPoliceman.erase(numOfPoliceman.begin()+i,numOfPoliceman.begin()+i);
            std::cout<<"Policeman is died.\n";

        }
    }
}
    void PolicemanIsDie() const
{
    this->numOfPoliceman[numOfPoliceman.size()-1]->isDie();
}
    void SetWorkerList(unsigned int num)
{
    for (unsigned int i = 0; i<num;i++)
    {
        AddToWorkerList(new Worker(eatWorker,createEat));
    }
}
    void AddToWorkerList(Worker *ant)
{
    this->numOfWorkers.push_back(ant);   
}
void addFoodToWareHouse()
{
    for (const auto element : numOfWorkers)
    {
        std::cout<<"Add eat in anthill.\n";
        if (startEat<wareHouseOfEatSize)
        {
            startEat += element->getCreateEat()*growthByPercent();
            std::cout<<"Eat:"<<startEat<<"\n";
        }
    }
}
    void eatWorkers()
{
for (int i =0; i<numOfWorkers.size();i++)
    {
        if (startEat>=numOfWorkers[i]->getEat())
        {
            startEat -= numOfWorkers[i]->getEat();
            std::cout<<"Worker is eating.\n";

        }
        else
        {
            numOfWorkers.erase(numOfWorkers.begin()+i,numOfWorkers.begin()+i);
            std::cout<<"Worker is died.\n";
        }
    }
}
    void WorkerIsDie() const
{
    numOfWorkers[numOfWorkers.size()-1]->isDie();
}
    void addToLarvaList(Larva* larva)
{
    numOfLarva.push_back(larva);
}
    void LarvaIsDie() const
{
    numOfLarva[numOfLarva.size()-1]->isDie();
}
    void eatLarvas()
{
for(int i = 0; i<numOfLarva.size();i++)
    {
            if (startEat>=numOfLarva[i]->getEat())
            {
                startEat -= numOfLarva[i]->getEat();
                std::cout<<"Larva is eating.\n";

            }
            else
            {
                numOfLarva.erase(numOfLarva.begin()+i,numOfLarva.begin()+i);
                std::cout<<"Larva is died.\n";
            }
    }
}
    void addDaysToLarva() const
    { 
    for (const auto element : numOfLarva)
    {
        element->setDay(element->getDay()+1);
    }
}
    void transform()
{
    for (const auto element : numOfLarva)
    {
        if(element->signalToWomb() == true)
        {
            int type = WombSingle->typeOfAnt(std::rand());
            //element->isDie();
            if (type == 0)
            {
                AddToSoldierList(new Soldier(eatSoldier,dieOfPest));
                std::cout<<"Create new soldier.\n";

            } else if(type == 1){
                AddToPolicemanList(new Policeman(eatPolicemen,growthCreateEatByPercent));
                std::cout<<"Create new policeman.\n";
            }
            else{
            AddToWorkerList(new Worker(eatWorker,createEat));
                std::cout<<"Create new worker.\n";
            }
        }
    }
    numOfLarva.erase(std::remove_if(numOfLarva.begin(),
                                numOfLarva.end(),
                                [&](Larva* stopPoint)-> bool 
                                       { return stopPoint->getDay()==3;}), 
                 numOfLarva.end());
    //std::_Erase_remove_if()
    //numOfLarva.erase(std::remove_if(numOfLarva[0],numOfLarva[numOfLarva.size()-1],))
}
    double getWareHouseOfEat() const
    {
        return wareHouseOfEatSize;
    }
    void setWareHouseOfEat(int value)
    {
        wareHouseOfEatSize = value;
    }
    size_t getNumOfSoldiers() const
    {
        return numOfSoldiers.size();
    }
    size_t getNumOfPoliceman() const
    {
        return numOfPoliceman.size();
    }
    size_t getNumOfWorkers() const
    {
        return numOfWorkers.size();
    }
    double getStartEat() const
{
    return startEat;
}
    
    void randomAttack(std::vector<Pest*> pest) 
{
    bool rand = (std::rand()%2);
    if (rand == true && !pest.empty())
    {
        isCareAnthill(pest);
    }
}
    void anthillToString()
{
    std::cout<<"Eat: "<<startEat<<", womb:"<<WombSingle<<", num of soldiers:"<<numOfSoldiers.size()<<
", num of policemen:"<<numOfPoliceman.size()<<", num of workers:"<<numOfWorkers.size()<<".\n";
}
};
