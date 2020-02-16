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

#include <iostream>

#include "Pet.h"
#include "Human.h"
#include "Synthesizer.h"
#include "Sequencer.h"
#include "Composition.h"
#include "Wrappers.h"

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
