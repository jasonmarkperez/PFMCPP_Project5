#pragma once

#include "Synthesizer.h"
#include "Sequencer.h"

#include <iostream>
#include <vector>
#include "LeakedObjectDetector.h"

struct Composition
{
    std::vector<Synthesizer> synths;
    std::vector<Sequencer> seqs;

    FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
    Composition(std::vector<Synthesizer> synthesizers, std::vector<Sequencer> sequencers) : synths(synthesizers), seqs(sequencers)
    {
        std::cout << "A composition is created featuring:" << std::endl;
        for(auto& synthesizer : synthesizers)
        {   
            std::cout << synthesizer.synthName << std::endl; 
        }
    }

    void addCommand(std::string synth, std::string command, std::string sequencer);

    FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
    ~Composition()
    {
        std::cout << "A composition is destroyed." << std::endl;
    }
    JUCE_LEAK_DETECTOR(Composition)
};
