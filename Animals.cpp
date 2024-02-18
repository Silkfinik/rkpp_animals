#include "Animals.h"
#include <iostream>

__int16 Animal::count = 0;

void Owner::SetName(const std::string& _name) {
    o_name = _name;
}

void Owner::SetAdress(const std::string& _adress) {
    adress = _adress;
}

void Owner::SetPhone(const std::string& _phone) {
    phone = _phone;
}

void Owner::SetBDate(const std::string& _b_date) {
    b_date = _b_date;
}

std::string Owner::GetName() const {
    return o_name.value();
}

std::string Owner::GetAdress() const {
    return adress.value();
}

std::string Owner::GetPhone() const {
    return phone.value();
}

std::string Owner::GetBDate() const {
    return b_date.value();
}


void Dog::MakeSound() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::SetBreed(const std::string& _breed) {
    breed = _breed;
}

std::string Dog::GetBreed() const {
    return breed.value();
}


void Cat::MakeSound() const {
    std::cout << "Meow!" << std::endl;
}

void Cat::SetColor(const std::string& _color) {
    color = _color;
}

std::string Cat::GetColor() const {
    return color.value();
}


void Parrot::MakeSound() const {
    std::cout << "Squawk!" << std::endl;
}

void Parrot::SetLexicon(const __int16& _lexicon) {
    lexicon = _lexicon;
}

__int16 Parrot::GetLexicon() const {
    return lexicon.value();
}


void Fish::MakeSound() const {
    std::cout << "Blub!" << std::endl;
}

void Fish::SetAvgDepth(const __int16& _avg_depth) {
    avg_depth = _avg_depth;
}

__int16 Fish::GetAvgDepth() const {
    return avg_depth.value();
}


void Pig::MakeSound() const {
    std::cout << "Oink!" << std::endl;
}

void Pig::SetPigletSize(const __int16& _piglet_size) {
    piglet_size = _piglet_size;
}

__int16 Pig::GetPigletSize() const {
    return piglet_size.value();
}

std::string cut_fill(std::string& line, const char& symbol) {
    std::string temp = line.substr(0, line.find(symbol));
    line.erase(0, line.find(symbol) + 1);
    return temp;
}

void read_file(const std::string& filename, std::map<std::string, std::vector<Animal*>>& pets) {
    std::ifstream input_file(filename);
    try {
        if(!input_file.is_open()) {
            throw "File not found!";
        }
        std::string line;
        while (std::getline(input_file, line)){
            std::string o_name;
            std::string adress;
            std::string phone;
            std::string b_date;
            std::string a_type;
            std::string a_name;
            __int16 a_age;
            o_name = cut_fill(line, ';');
            adress = cut_fill(line, ';');
            phone = cut_fill(line, ';');
            b_date = cut_fill(line, ';');
            a_type = cut_fill(line, ';');
            a_name = cut_fill(line, ';');
            a_age = std::stoi(line);
            Owner owner(o_name, adress, phone, b_date);
            if (a_type == "Собака") {
                pets[owner.GetName()].push_back(new Dog(owner, a_name, a_age));
            }
            else if (a_type == "Кошка") {
                std::string color = cut_fill(line, ';');
                pets[owner.GetName()].push_back(new Cat(owner, a_name, a_age));
            }
            else if (a_type == "Попугай") {
                pets[owner.GetName()].push_back(new Parrot(owner, a_name, a_age));
            }
            else if (a_type == "Рыбка") {
                pets[owner.GetName()].push_back(new Fish(owner, a_name, a_age));
            }
            else if (a_type == "Свинка") {
                pets[owner.GetName()].push_back(new Pig(owner, a_name, a_age));
            }
            else {
                throw "Unknown animal type!";
            }
        }
    }
    catch (const char* err) {
        std::cerr << err << std::endl;
    }
}