#include "Wrappers.h"

PetWrapper::PetWrapper(Pet* ptr) : pointerToPet(ptr) {}
PetWrapper::~PetWrapper()
{
    delete pointerToPet;
}

HumanWrapper::HumanWrapper(Human* ptr) : pointerToHuman(ptr) {}
HumanWrapper::~HumanWrapper()
{
    delete pointerToHuman;
}

SynthesizerWrapper::SynthesizerWrapper(Synthesizer* ptr) : pointerToSynthesizer(ptr){}
SynthesizerWrapper::~SynthesizerWrapper()
{
    delete pointerToSynthesizer;
}

SequencerWrapper::SequencerWrapper(Sequencer* ptr) : pointerToSequencer(ptr){}
SequencerWrapper::~SequencerWrapper()
{
    delete pointerToSequencer;
}

CompositionWrapper::CompositionWrapper(Composition* ptr) : pointerToComposition(ptr){}
CompositionWrapper::~CompositionWrapper(){
    delete pointerToComposition;
}
