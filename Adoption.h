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
