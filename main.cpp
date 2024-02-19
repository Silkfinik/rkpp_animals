#include "Animals.cpp"

int main() {
    std::vector<Animal*> pets;
    ReadFile("input.txt", pets);
    PrintPets(pets);
    DifTypesByOwner(pets);
    OwnersAndNamesByType(pets);
    AmountOfTypesByName(pets);
    YoungestOldestOfEachSpecies(pets);
    RewriteFile("input.txt", pets);
    return 0;
}