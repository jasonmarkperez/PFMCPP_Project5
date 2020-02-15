#pragma once

#include "LeakedObjectDetector.h"
#include <iostream>

struct Synthesizer 
{
    unsigned int polyphony, notesOn;
    std::string synthName;
    Synthesizer(std::string name) : polyphony(16), notesOn(0), synthName(name) {
        std::cout << "A synthesizer is created " << synthName << std::endl;
    }
    ~Synthesizer()
    {
        std::cout << "A synthesizer is destroyed " <<
        synthName << std::endl;
    }
    void noteOn();
    void noteOff();

    JUCE_LEAK_DETECTOR(Synthesizer)
};
