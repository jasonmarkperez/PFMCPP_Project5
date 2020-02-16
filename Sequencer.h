#pragma once

#include "Synthesizer.h"
#include "LeakedObjectDetector.h"
#include <iostream>
#include <vector>

struct Sequencer
{
    Sequencer(std::string seqName);
    ~Sequencer();

    bool isPlaying, playForward, playReverse;
    std::vector<int> notes;
    std::string name;


    void recordNote(int note);
    void playBack(Synthesizer synth);
    void setForwardPlayback();
    void setReversePlayback();
    
    JUCE_LEAK_DETECTOR(Sequencer)
};
