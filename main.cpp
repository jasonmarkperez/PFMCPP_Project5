/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */



/*
 copied UDT 1:
 */
#include <iostream>
#include <vector>
#include "LeakedObjectDetector.h"

struct Pet 
{
    bool isCat, isDog, isPetHappy, isPetHungry;
    int age;
    double foodLevel;
    std::string name;

    Pet(std::string petType, std::string petName) : isCat(false), isDog(false), isPetHappy(false), isPetHungry(false), age(0), foodLevel(10.0), name(petName)
    { 
        std::cout << "A " << petType << " named " << petName << " is born!" << std::endl;

        if(petType == "cat")
        {
            std::cout << "meow" << std::endl;
            this->isCat = true;
        }
        else if (petType == "dog")
        {
            std::cout << "woof" << std::endl;
            this->isDog = false;
        }
        else {
            //handle other pet types
        }
    }

    ~Pet()
    {
        std::cout << "A pet is destroyed, RIP " << this->name << std::endl;
    }

    void feed()
    {
        std::cout << "nom" << std::endl;
        this->isPetHungry = false;
        this->isPetHappy = true;
    }

    void walk(int howLong)
    {   
        if(isPetHungry == false)
        {
            std::cout << "walking " << this->name << " for " << howLong << " minutes " << std::endl;
            while(howLong > 0)
            {
                std::cout << ".";
                howLong --;
                this->foodLevel = this->foodLevel - 0.25;

                if(this->foodLevel < 5 and this->foodLevel > 1)
                {
                    std::cout << this->name << " is getting hungry!!" << std::endl;
                }

                if(foodLevel < 1)
                {
                    std::cout << this->name << " is too hungry to walk, time to eat!" << std::endl;
                    howLong = 0;
                    this->isPetHungry = true;
                }
            }
            std::cout << std::endl;
        }
        else 
        {
            std::cout << this->name << " is hungry, let's eat first! " << std::endl;
        }
        
        std::cout << "Done walking " << this->name << std::endl;
        this->isPetHappy = true;
    }

    void status()
    {
        std::cout << this->name;
        this->isPetHungry ?  std::cout << " is" : std::cout << " is not";
        std::cout << " hungry" << std::endl;
        
        std::cout << "food level: " << this->foodLevel << std::endl;

        std::cout << this->name;
        this->isPetHappy ?  std::cout << " is" : std::cout << " is not";
        std::cout << " happy" << std::endl;
    }
    JUCE_LEAK_DETECTOR(Pet)
};

/*
 copied UDT 2:
 */

struct Human
{
    int numberOfViolations, numberOfCars, numberOfPets;
    std::string name;
    bool licenseIsValid, hasBike;
    std::vector<Pet> pets;

    Human(std::string humanName) : numberOfViolations(0), numberOfCars(0), numberOfPets(0), name(humanName), licenseIsValid(false), hasBike(false), pets({})
    { 
        std::cout << "A human is created, hello " << name << std::endl;
    }

    ~Human()
    {
        std::cout << "A human is destroyed, RIP " << name << std::endl;
    }

    void adoptPet(Pet pet)
    {
        this->numberOfPets ++;
        this->pets.push_back(pet);
        std::cout << this->name << " has adopted " << pet.name << std::endl;
    }

    void printNumberOfPets()
    {
        std::cout << this->name << " has: " << this->numberOfPets << " pet(s)." << std::endl; 
    }

    bool isDriverAllowedToDrive();
    std::string isPetHungry(Pet ourPet)
    {
        if(ourPet.isPetHungry)
        {
            return "Pet is hungry!";
        }
        else 
        {
            return "Pet is not hungry";
        }
    }
    JUCE_LEAK_DETECTOR(Human)
};

/*
 copied UDT 3:
 */

struct Synthesizer 
{
    unsigned int polyphony, notesOn;
    std::string synthName;
    Synthesizer(std::string name) : polyphony(16), notesOn(0), synthName(name) {
        std::cout << "A synthesizer is created " << synthName << std::endl;
    }
    ~Synthesizer()
    {
        std::cout << "A synthesizer is destroyed " <<
        synthName << std::endl;
    }
    void noteOn()
    {
        if(this->notesOn < this->polyphony) 
        {
            std::cout << " -note on- ";
            ++ this->notesOn;
        }
    }
    void noteOff()
    {
        std::cout << " -note off- ";
        -- this->notesOn;
    }
    JUCE_LEAK_DETECTOR(Synthesizer)
};

struct Sequencer
{
    bool isPlaying, playForward, playReverse;
    std::vector<int> notes;
    std::string name;

    Sequencer(std::string seqName) : isPlaying(0), playForward(true), playReverse(false), notes({}), name(seqName)
    {}

    void recordNote(int note)
    {
        notes.push_back(note);
    }

    void playBack(Synthesizer synth)
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

    void setForwardPlayback()
    {
        this->playForward = true;
        this->playReverse = false;
    }

    void setReversePlayback()
    {
        this->playForward = false;
        this->playReverse = true;
    }
    JUCE_LEAK_DETECTOR(Sequencer)
};

/*
 new UDT 4:
 */

struct Composition
{
    std::vector<Synthesizer> synths;
    std::vector<Sequencer> seqs;

    Composition(std::vector<Synthesizer> synthesizers, std::vector<Sequencer> sequencers) : synths(synthesizers), seqs(sequencers)
    {
        std::cout << "A composition is created featuring:" << std::endl;
        for(auto& synthesizer : synthesizers)
        {   
            std::cout << synthesizer.synthName << std::endl; 
        }
    }

    void addCommand(std::string synth, std::string command, std::string sequencer)
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

    ~Composition()
    {
        std::cout << "A composition is destroyed." << std::endl;
    }
    JUCE_LEAK_DETECTOR(Composition)
};


/*
 new UDT 5:
 */

struct Adoption
{
    Human adopter;
    Pet adoptee;

    Adoption(Human human, Pet pet) : adopter(human), adoptee(pet) {
        adopter.adoptPet(pet);
    }

    ~Adoption()
    {
        std::cout << "Adoption is complete." << std::endl;
    }
    JUCE_LEAK_DETECTOR(Adoption)
};

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


int main()
{
    PetWrapper zuul(new Pet("cat", "Zuul"));
    std::cout << "Hello " << zuul.pointerToPet->name << std::endl;
    HumanWrapper jason(new Human("Jason"));
    jason.pointerToHuman->adoptPet(*zuul.pointerToPet);
    std::cout << "Jason has: " << jason.pointerToHuman->numberOfPets << " pet(s)." << std::endl;
    jason.pointerToHuman->printNumberOfPets();
    std::cout << "---" << std::endl;
    SynthesizerWrapper moog(new Synthesizer("Mother32"));
    SynthesizerWrapper korg(new Synthesizer("Sigma"));

    std::cout << "Moog's polyphony: " << moog.pointerToSynthesizer->polyphony << std::endl;
    
    SequencerWrapper mc202(new Sequencer("MC202"));
    SequencerWrapper msq8(new Sequencer("SQD-1"));
    mc202.pointerToSequencer->recordNote(99);
    mc202.pointerToSequencer->recordNote(24);
    mc202.pointerToSequencer->recordNote(77);

    CompositionWrapper newSong(new Composition({*moog.pointerToSynthesizer, *korg.pointerToSynthesizer}, {*mc202.pointerToSequencer}));
    
    newSong.pointerToComposition->addCommand("Mother32", "plays", "MC202");
}
