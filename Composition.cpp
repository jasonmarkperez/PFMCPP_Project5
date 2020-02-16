#include "Composition.h"
#include <iostream>

Composition::Composition(std::vector<Synthesizer> synthesizers, std::vector<Sequencer> sequencers) : synths(synthesizers), seqs(sequencers)
{
    std::cout << "A composition is created featuring:" << std::endl;
    for(auto& synthesizer : synthesizers)
    {   
        std::cout << synthesizer.synthName << std::endl; 
    }
}

Composition::~Composition()
{
    std::cout << "A composition is destroyed." << std::endl;
}

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
