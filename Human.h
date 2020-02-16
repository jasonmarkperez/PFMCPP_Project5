#pragma once

#include "Pet.h"
#include "LeakedObjectDetector.h"
#include <iostream>
#include <vector>

struct Human
{
    Human(std::string humanName);
    ~Human();

    int numberOfViolations, numberOfCars, numberOfPets;
    std::string name;
    bool licenseIsValid, hasBike;
    std::vector<Pet> pets;

    void adoptPet(Pet pet);
    void printNumberOfPets();
    bool isDriverAllowedToDrive();
    std::string isPetHungry(Pet ourPet);
    
    JUCE_LEAK_DETECTOR(Human)
};
