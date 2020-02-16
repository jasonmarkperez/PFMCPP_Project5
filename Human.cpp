#include "Human.h"
#include <iostream>

Human::Human(std::string humanName) : numberOfPets(0), name(humanName), licenseIsValid(false), hasBike(false), pets({})
{ 
    std::cout << "A human is created, hello " << name << std::endl;
}

Human::~Human()
{
    std::cout << "A human is destroyed, RIP " << name << std::endl;
}

void Human::Human::adoptPet(Pet pet)
{
    this->numberOfPets ++;
    this->pets.push_back(pet);
    std::cout << this->name << " has adopted " << pet.name << std::endl;
}

void Human::Human::printNumberOfPets()
{
    std::cout << this->name << " has: " << this->numberOfPets << " pet(s)." << std::endl; 
}

std::string Human::Human::isPetHungry(Pet ourPet)
{
    if(ourPet.isPetHungry)
    {
        return "Pet is hungry!";
    }
    else 
    {
        return "Pet is not hungry";
    }
}
