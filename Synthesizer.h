#pragma once

#include "LeakedObjectDetector.h"
#include <iostream>

struct Synthesizer 
{
    unsigned int polyphony, notesOn;
    std::string synthName;
    FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
    Synthesizer(std::string name) : polyphony(16), notesOn(0), synthName(name) {
        std::cout << "A synthesizer is created " << synthName << std::endl;
    }
        FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
    ~Synthesizer()
    {
        std::cout << "A synthesizer is destroyed " <<
        synthName << std::endl;
    }
    void noteOn();
    void noteOff();

    JUCE_LEAK_DETECTOR(Synthesizer)
};
