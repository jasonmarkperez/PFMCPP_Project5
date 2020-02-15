#pragma once

#include "Synthesizer.h"
#include "LeakedObjectDetector.h"
#include <iostream>
#include <vector>

struct Sequencer
{
    bool isPlaying, playForward, playReverse;
    std::vector<int> notes;
    std::string name;

    FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
    Sequencer(std::string seqName) : isPlaying(0), playForward(true), playReverse(false), notes({}), name(seqName)
    {}

    void recordNote(int note);
    void playBack(Synthesizer synth);
    void setForwardPlayback();
    void setReversePlayback();
    
    JUCE_LEAK_DETECTOR(Sequencer)
};
