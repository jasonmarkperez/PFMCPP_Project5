#pragma once

#include "Pet.h"
#include "Human.h"
#include "Synthesizer.h"
#include "Sequencer.h"
#include "Composition.h"

struct PetWrapper
{
    PetWrapper(Pet* ptr);
    ~PetWrapper();
    Pet* pointerToPet = nullptr;
};

struct HumanWrapper
{
    HumanWrapper(Human* ptr);
    ~HumanWrapper();
    Human* pointerToHuman = nullptr;
};

struct SynthesizerWrapper
{
    SynthesizerWrapper(Synthesizer* ptr);
    ~SynthesizerWrapper();
    Synthesizer* pointerToSynthesizer = nullptr;
};

struct SequencerWrapper
{
    SequencerWrapper(Sequencer* ptr);
    ~SequencerWrapper();
    Sequencer* pointerToSequencer = nullptr;
};

struct CompositionWrapper
{
    CompositionWrapper(Composition* ptr);
    ~CompositionWrapper();
    Composition* pointerToComposition = nullptr;
};
