#include "Sequencer.h"
#include "Synthesizer.h"
#include <iostream>

Sequencer::Sequencer(std::string seqName) : isPlaying(0), playForward(true), playReverse(false), notes({}), name(seqName) {}

Sequencer::~Sequencer() {}

void Sequencer::Sequencer::recordNote(int note)
{
    notes.push_back(note);
}

void Sequencer::Sequencer::playBack(Synthesizer synth)
{
    if(this->playForward)
    {
        std::cout << "playing forward:: ";
        for(auto& n : this->notes)
        {   
            std::cout << n << " "; 
            synth.noteOn();
            synth.noteOff();
        }
    }

    if(this->playReverse)
    {
        std::cout << "playing reverse:: ";
        for(auto n = this->notes.rbegin(); n != this->notes.rend(); ++n)
        {   
            std::cout << *n << " "; 
            synth.noteOn();
            synth.noteOff();
        }
    }
    std::cout << std::endl;
}

void Sequencer::Sequencer::setForwardPlayback()
{
    this->playForward = true;
    this->playReverse = false;
}

void Sequencer::Sequencer::setReversePlayback()
{
    this->playForward = false;
    this->playReverse = true;
}
