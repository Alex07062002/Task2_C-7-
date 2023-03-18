#include <vector>

#include "Anthill.h"
#include "Pest.h"
#include "windows.h"

static constexpr  int eatPest = 5;
static constexpr  int dieOfSoldier = 1;
static constexpr int burnPest = 3;


void run(Anthill* anthill, std::vector<Pest*> pests)
{
    anthill->randomAttack(pests);
    if (anthill->getNumOfSoldiers()==0) {
        return;
    }
    anthill->addFoodToWareHouse();
    anthill->randomAttack(pests);
    if (anthill->getNumOfSoldiers()==0) {
        return;
    }
    anthill->eatWomb();
    anthill->createLarva();
    anthill->eatLarvas();
    anthill->eatSoldiers();
    anthill->eatWorkers();
    anthill->eatPoliceman();
    anthill->randomAttack(pests);
    if (anthill->getNumOfSoldiers()==0) {
        return;
    }
    anthill->transform();
    anthill->randomAttack(pests);
    if (anthill->getNumOfSoldiers()==0) {
        return;
    }
    anthill->addDaysToLarva();
    anthill->anthillToString();
}

void burnOfPest(int num,std::vector<Pest*> pests)
{
    for (int i =0; i< num; i++)
    {
        pests.push_back(new Pest(eatPest,dieOfSoldier));
    }
}

   int main(){
    int day = 0;
        int numOfPest,numOfSoldier,numOfPoliceman,numOfWorker;
    double wareHouse,startEat;
    do
    {
        std::cout<<"Count eat blocks in  anthill warehouse:\n";
        std::cin>>wareHouse;
    }while (wareHouse<0);
    do
    {
        std::cout<<"Start count of eat:\n";
        std::cin>>startEat;
    }while (startEat<0);
    do
    {
        std::cout<<"Num of pests:\n";
        std::cin>>numOfPest;
    }while (numOfPest<0);
    do
    {
        std::wcout<<"Num of soldiers:\n";
        std::wcin>>numOfSoldier;
    }while (numOfSoldier<0);
    do
    {
        std::wcout<<"Num of policemen:\n";
        std::wcin>>numOfPoliceman;
    } while (numOfPoliceman<0);
    do
    {
        std::wcout<<"Num of workers:\n";
        std::wcin>>numOfWorker;
    }while (numOfWorker<0);
        Anthill* anthill = new Anthill(wareHouse, startEat,numOfSoldier,numOfPoliceman,numOfWorker);
        std::vector<Pest*> pests = std::vector<Pest*>();
        for (int i =0; i< numOfPest; i++)
        {
            pests.push_back(new Pest(eatPest,dieOfSoldier));
        }
    while (day != 1000)
    {
        run(anthill,pests);
        burnOfPest(burnPest,pests);
        ++day;
        std::cout<<"Day is "<<day<<".\n";
    }
    }

