#pragma once

#include "Pet.h"
#include "Human.h"
#include "Synthesizer.h"
#include "Sequencer.h"
#include "Composition.h"

struct PetWrapper
{
    PetWrapper(Pet* ptr) : pointerToPet(ptr){}
    ~PetWrapper(){
        delete pointerToPet;
    }

    Pet* pointerToPet = nullptr;
};

struct HumanWrapper
{
    HumanWrapper(Human* ptr) : pointerToHuman(ptr){}
    ~HumanWrapper(){
        delete pointerToHuman;
    }

    Human* pointerToHuman = nullptr;
};

struct SynthesizerWrapper
{
    SynthesizerWrapper(Synthesizer* ptr) : pointerToSynthesizer(ptr){}
    ~SynthesizerWrapper(){
        delete pointerToSynthesizer;
    }

    Synthesizer* pointerToSynthesizer = nullptr;
};

struct SequencerWrapper
{
    SequencerWrapper(Sequencer* ptr) : pointerToSequencer(ptr){}
    ~SequencerWrapper(){
        delete pointerToSequencer;
    }

    Sequencer* pointerToSequencer = nullptr;
};

struct CompositionWrapper
{
    CompositionWrapper(Composition* ptr) : pointerToComposition(ptr){}
    ~CompositionWrapper(){
        delete pointerToComposition;
    }

    Composition* pointerToComposition = nullptr;
};
