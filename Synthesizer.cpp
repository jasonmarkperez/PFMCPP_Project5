#include "Synthesizer.h"
#include <iostream>

Synthesizer::Synthesizer(std::string name) : polyphony(16), notesOn(0), synthName(name) 
{
    std::cout << "A synthesizer is created " << synthName << std::endl;
}

Synthesizer::~Synthesizer()
{
    std::cout << "A synthesizer is destroyed " <<
    synthName << std::endl;
}

void Synthesizer::Synthesizer::noteOn()
{
    if(this->notesOn < this->polyphony) 
    {
        std::cout << " -note on- ";
        ++ this->notesOn;
    }
}
void Synthesizer::Synthesizer::noteOff()
{
    std::cout << " -note off- ";
    -- this->notesOn;
}
