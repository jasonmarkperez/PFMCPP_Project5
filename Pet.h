#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct Pet 
{
    bool isCat, isDog, isPetHappy, isPetHungry;
    int age;
    double foodLevel;
    std::string name;

    Pet(std::string petType, std::string petName) : isCat(false), isDog(false), isPetHappy(false), isPetHungry(false), age(0), foodLevel(10.0), name(petName)
    { 
        std::cout << "A " << petType << " named " << petName << " is born!" << std::endl;

        if(petType == "cat")
        {
            std::cout << "meow" << std::endl;
            this->isCat = true;
        }
        else if (petType == "dog")
        {
            std::cout << "woof" << std::endl;
            this->isDog = false;
        }
        else {
            //handle other pet types
        }
    }

    ~Pet()
    {
        std::cout << "A pet is destroyed, RIP " << this->name << std::endl;
    }

    void feed();
    void walk(int howLong);
    void status();
    
    JUCE_LEAK_DETECTOR(Pet)
};
