#pragma once

#include "Pet.h"
#include "Human.h"
#include "Synthesizer.h"
#include "Sequencer.h"
#include "Composition.h"

FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
struct PetWrapper
{
    PetWrapper(Pet* ptr) : pointerToPet(ptr){}
    ~PetWrapper(){
        delete pointerToPet;
    }

    Pet* pointerToPet = nullptr;
};

FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
struct HumanWrapper
{
    HumanWrapper(Human* ptr) : pointerToHuman(ptr){}
    ~HumanWrapper(){
        delete pointerToHuman;
    }

    Human* pointerToHuman = nullptr;
};

FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
struct SynthesizerWrapper
{
    SynthesizerWrapper(Synthesizer* ptr) : pointerToSynthesizer(ptr){}
    ~SynthesizerWrapper(){
        delete pointerToSynthesizer;
    }

    Synthesizer* pointerToSynthesizer = nullptr;
};

FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
struct SequencerWrapper
{
    SequencerWrapper(Sequencer* ptr) : pointerToSequencer(ptr){}
    ~SequencerWrapper(){
        delete pointerToSequencer;
    }

    Sequencer* pointerToSequencer = nullptr;
};

FIXME 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
struct CompositionWrapper
{
    CompositionWrapper(Composition* ptr) : pointerToComposition(ptr){}
    ~CompositionWrapper(){
        delete pointerToComposition;
    }

    Composition* pointerToComposition = nullptr;
};
