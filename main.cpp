#include "Animals.cpp"

int main() {
    std::map<std::string, std::vector<Animal*>> pets;
    read_file("input.txt", pets);
}