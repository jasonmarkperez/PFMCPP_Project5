#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct Pet 
{
    Pet(std::string petType, std::string petName);
    ~Pet();

    bool isCat, isDog, isPetHappy, isPetHungry;
    int age;
    double foodLevel;
    std::string name;

    void feed();
    void walk(int howLong);
    void status();
    
    JUCE_LEAK_DETECTOR(Pet)
};
