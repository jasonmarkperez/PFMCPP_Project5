#include "Human.h"
#include "Pet.h"
#include <iostream>

void Human::adoptPet(Pet pet)
{
    this->numberOfPets ++;
    this->pets.push_back(pet);
    std::cout << this->name << " has adopted " << pet.name << std::endl;
}

void Human::printNumberOfPets()
{
    std::cout << this->name << " has: " << this->numberOfPets << " pet(s)." << std::endl; 
}

std::string Human::isPetHungry(Pet ourPet)
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
