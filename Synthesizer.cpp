#include "Synthesizer.h"
#include <iostream>

void Synthesizer::noteOn()
{
    if(this->notesOn < this->polyphony) 
    {
        std::cout << " -note on- ";
        ++ this->notesOn;
    }
}
void Synthesizer::noteOff()
{
    std::cout << " -note off- ";
    -- this->notesOn;
}
