struct Adoption
{
    Human adopter;
    Pet adoptee;

    Adoption(Human human, Pet pet) : adopter(human), adoptee(pet) { FIXME  5) NO IN-CLASS IMPLEMENTATION ALLOWED.
        adopter.adoptPet(pet);
    }

    ~Adoption() FIXME  5) NO IN-CLASS IMPLEMENTATION ALLOWED.
    {
        std::cout << "Adoption is complete." << std::endl;
    }
    JUCE_LEAK_DETECTOR(Adoption)
};
