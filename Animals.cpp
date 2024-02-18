#include "Animals.h"
#include <iostream>

__int16 Animal::count = 1;

void Animal::SetOwner(const Owner& _owner) {
    owner = _owner;
}

void Animal::SetAName(const std::string& _name) {
    a_name = _name;
}

void Animal::SetAge(const __int16& _age) {
    age = _age;
}

std::string Animal::GetAName() const {
    return a_name.value();
}

__int16 Animal::GetAge() const {
    return age.value();
}

Owner& Animal::GetOwner() {
    return owner.value();
}

__int16 Animal::GetId() const {
    return id;
}


void Owner::SetOName(const std::string& _name) {
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

std::string Owner::GetOName() const {
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

void ReadFile(const std::string& filename, std::vector<Animal*>& pets) {
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
            if(!line.empty()) {
                a_age = std::stoi(line);
            }
            Owner owner(o_name, adress, phone, b_date);
            if (a_type == "Dog") {
                pets.push_back(new Dog(owner, a_name, a_age)) ;
            }
            else if (a_type == "Cat") {
                pets.push_back(new Cat(owner, a_name, a_age));
            }
            else if (a_type == "Parrot") {
                pets.push_back(new Parrot(owner, a_name, a_age));
            }
            else if (a_type == "Fish") {
                pets.push_back(new Fish(owner, a_name, a_age));
            }
            else if (a_type == "Pig") {
                pets.push_back(new Pig(owner, a_name, a_age));
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

void PrintPets(const std::vector<Animal*>& pets) {
    for (auto& pet : pets) {
        std::string type = typeid(*pet).name();
        type = type.substr(1);
        std::cout << "ID: " << pet->GetId() << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Name: " << pet->GetAName() << std::endl;
        std::cout << "Age: " << pet->GetAge() << std::endl;
        std::cout << "Adress: " << pet->GetOwner().GetAdress() << std::endl;
        std::cout << "Owner name: " << pet->GetOwner().GetOName() << std::endl;
        std::cout << "Owner phone: " << pet->GetOwner().GetPhone() << std::endl;
        std::cout << "Owner birth date: " << pet->GetOwner().GetBDate() << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}

void RewriteFile(const std::string& filename, const std::vector<Animal*>& pets) {
    std::ofstream output_file(filename);
    for (auto& pet : pets) {
        std::string type = typeid(*pet).name();
        type = type.substr(1);
        output_file << pet->GetOwner().GetOName() << ";";
        output_file << pet->GetOwner().GetAdress() << ";";
        output_file << pet->GetOwner().GetPhone() << ";";
        output_file << pet->GetOwner().GetBDate() << ";";
        output_file << type << ";";
        output_file << pet->GetAName() << ";";
        output_file << pet->GetAge() << std::endl;
    }
}

