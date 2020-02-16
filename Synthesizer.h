#pragma once

#include "LeakedObjectDetector.h"
#include <iostream>

struct Synthesizer 
{
    Synthesizer(std::string name);
    ~Synthesizer();

    unsigned int polyphony, notesOn;
    std::string synthName;

    void noteOn();
    void noteOff();

    JUCE_LEAK_DETECTOR(Synthesizer)
};
