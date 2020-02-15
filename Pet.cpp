#include "Pet.h"
#include <iostream>

void Pet::feed()
{
    std::cout << "nom" << std::endl;
    this->isPetHungry = false;
    this->isPetHappy = true;
}

void Pet::walk(int howLong)
{   
    if(isPetHungry == false)
    {
        std::cout << "walking " << this->name << " for " << howLong << " minutes " << std::endl;
        while(howLong > 0)
        {
            std::cout << ".";
            howLong --;
            this->foodLevel = this->foodLevel - 0.25;

            if(this->foodLevel < 5 and this->foodLevel > 1)
            {
                std::cout << this->name << " is getting hungry!!" << std::endl;
            }

            if(foodLevel < 1)
            {
                std::cout << this->name << " is too hungry to walk, time to eat!" << std::endl;
                howLong = 0;
                this->isPetHungry = true;
            }
        }
        std::cout << std::endl;
    }
    else 
    {
        std::cout << this->name << " is hungry, let's eat first! " << std::endl;
    }
    
    std::cout << "Done walking " << this->name << std::endl;
    this->isPetHappy = true;
}

void Pet::status()
{
    std::cout << this->name;
    this->isPetHungry ?  std::cout << " is" : std::cout << " is not";
    std::cout << " hungry" << std::endl;
    
    std::cout << "food level: " << this->foodLevel << std::endl;

    std::cout << this->name;
    this->isPetHappy ?  std::cout << " is" : std::cout << " is not";
    std::cout << " happy" << std::endl;
}
