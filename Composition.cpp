#include "Composition.h"
#include <iostream>

void Composition::addCommand(std::string synth, std::string command, std::string sequencer)
{
    for(auto& seq : this->seqs)
    {
        if(seq.name == sequencer)
        {
            for(auto& s : this->synths)
            {   
                if(s.synthName == synth)
                {
                    std::cout << seq.name << " " <<command << " " << s.synthName << std::endl;
                    seq.playBack(s);
                }
            }
        }
    }
}
