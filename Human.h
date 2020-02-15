#pragma once

#include "Pet.h"
#include "LeakedObjectDetector.h"
#include <iostream>
#include <vector>

struct Human
{
    int numberOfViolations, numberOfCars, numberOfPets;
    std::string name;
    bool licenseIsValid, hasBike;
    std::vector<Pet> pets;

    Human(std::string humanName) : numberOfViolations(0), numberOfCars(0), numberOfPets(0), name(humanName), licenseIsValid(false), hasBike(false), pets({})
    { 
        std::cout << "A human is created, hello " << name << std::endl;
    }

    ~Human()
    {
        std::cout << "A human is destroyed, RIP " << name << std::endl;
    }

    void adoptPet(Pet pet);
    void printNumberOfPets();
    bool isDriverAllowedToDrive();
    std::string isPetHungry(Pet ourPet);
    
    JUCE_LEAK_DETECTOR(Human)
};
