#include "Animals.h"

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

std::string Owner::GetName() {
    return o_name.value();
}

std::string Owner::GetAdress() {
    return adress.value();
}

std::string Owner::GetPhone() {
    return phone.value();
}

std::string Owner::GetBDate() {
    return b_date.value();
}


void Dog::Do() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::SetBreed(const std::string& _breed) {
    breed = _breed;
}

std::string Dog::GetBreed() {
    return breed.value();
}


void Cat::Do() const {
    std::cout << "Meow!" << std::endl;
}

void Cat::SetColor(const std::string& _color) {
    color = _color;
}

std::string Cat::GetColor() {
    return color.value();
}


void Parrot::Do() const {
    std::cout << "Squawk!" << std::endl;
}

void Parrot::SetLexicon(const __int16& _lexicon) {
    lexicon = _lexicon;
}

__int16 Parrot::GetLexicon() {
    return lexicon.value();
}


void Fish::Do() const {
    std::cout << "Blub!" << std::endl;
}

void Fish::SetAvgDepth(const __int16& _avg_depth) {
    avg_depth = _avg_depth;
}

__int16 Fish::GetAvgDepth() {
    return avg_depth.value();
}


void Pig::Do() const {
    std::cout << "Oink!" << std::endl;
}

void Pig::SetPigletSize(const __int16& _piglet_size) {
    piglet_size = _piglet_size;
}

__int16 Pig::GetPigletSize() {
    return piglet_size.value();
}

