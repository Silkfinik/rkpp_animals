#include "Animals.cpp"

int main() {
    std::vector<Animal*> pets;
    ReadFile("input.txt", pets);
    PrintPets(pets);
    RewriteFile("input.txt", pets);
    return 0;
}