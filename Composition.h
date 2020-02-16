#pragma once

#include "Synthesizer.h"
#include "Sequencer.h"

#include <iostream> 
#include <vector>
#include "LeakedObjectDetector.h"

struct Composition
{
    Composition(std::vector<Synthesizer> synthesizers, std::vector<Sequencer> sequencers);
    ~Composition();

    std::vector<Synthesizer> synths;
    std::vector<Sequencer> seqs;

    void addCommand(std::string synth, std::string command, std::string sequencer);

    JUCE_LEAK_DETECTOR(Composition)
};
