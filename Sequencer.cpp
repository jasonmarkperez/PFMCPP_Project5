#include "Sequencer.h"
#include "Synthesizer.h"
#include <iostream>

void Sequencer::recordNote(int note)
{
    notes.push_back(note);
}

void Sequencer::playBack(Synthesizer synth)
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

void Sequencer::setForwardPlayback()
{
    this->playForward = true;
    this->playReverse = false;
}

void Sequencer::setReversePlayback()
{
    this->playForward = false;
    this->playReverse = true;
}
