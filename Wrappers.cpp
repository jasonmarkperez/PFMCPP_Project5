#include "Wrappers.h"
#include "Pet.h"
#include "Human.h"
#include "Synthesizer.h"
#include "Sequencer.h"
#include "Composition.h"

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
