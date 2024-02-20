#include "Animals.cpp"

int main() {
    std::vector<Animal*> pets;
    try {
        ReadFile("input.txt", pets);
        Menu(pets);
    } catch (const char* err) {
        std::cerr << err << std::endl;
    }
    return 0;
}