#include "Animals.cpp"

int main() {
    std::vector<Animal*> pets;
    ReadFile("input.txt", pets);
    Menu(pets);
    return 0;
}