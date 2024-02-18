#include "Animals.cpp"

int main() {
    std::map<std::string, std::vector<Animal*> > animals;
    read_file("input.txt", animals);
    return 0;
}