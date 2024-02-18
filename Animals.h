#ifndef ANIMALS_H
#define ANIMALS_H


#include <string>
#include <optional>
#include <vector>
#include <map>
#include <fstream>

class Owner {
private:
    std::optional<std::string> o_name;
    std::optional<std::string> adress;
    std::optional<std::string> phone;
    std::optional<std::string> b_date;
public:
    Owner (std::string _name, std::string _adress, std::string _phone, std::string _b_date) :
    o_name(std::move(_name)), adress(std::move(_adress)),
    phone(std::move(_phone)), b_date(std::move(_b_date)) {};

    Owner() = default;

    void SetName(const std::string& _name);
    void SetAdress(const std::string& _adress);
    void SetPhone(const std::string& _phone);
    void SetBDate(const std::string& _b_date);

    [[nodiscard]] std::string GetName() const;
    [[nodiscard]] std::string GetAdress() const;
    [[nodiscard]] std::string GetPhone() const;
    [[nodiscard]] std::string GetBDate() const;
};

class Animal {
private:
    static __int16 count;
protected:
    std::optional<Owner> owner;
    std::optional <std::string> a_name;
    std::optional <__int16> age;
    const __int16 id;
public:
    Animal() : id(count++) {};

    explicit Animal(Owner _owner) : owner(std::move(_owner)), id(count++) {};

    explicit Animal(std::string _name) : a_name(std::move(_name)), id(count++) {};

    Animal (Owner _owner, std::string _name) : owner(std::move(_owner)), a_name(std::move(_name)), id(count++) {};

    Animal (Owner _owner, std::string _name, const __int16& _age) : owner(std::move(_owner)),
    a_name(std::move(_name)), age(_age), id(count++) {};

    virtual void MakeSound() const = 0;

    virtual ~Animal() = default;
};

class Dog : public Animal {
private:
    std::optional<std::string> breed;
public:
    using Animal::Animal;
    Dog (Owner _owner, std::string _name, const __int16& _age, std::string _breed) : Animal(std::move(_owner),
        std::move(_name), _age), breed(std::move(_breed)) {};

    void MakeSound() const override;

    [[nodiscard]] std::string GetBreed() const;

    void SetBreed(const std::string& _breed);
};

class Cat : public Animal {
private:
    std::optional<std::string> color;
public:
    using Animal::Animal;
    Cat (Owner _owner, std::string _name, const __int16& _age, std::string _color) : Animal(std::move(_owner),
        std::move(_name), _age), color(std::move(_color)) {};

    void MakeSound() const override;

    [[nodiscard]] std::string GetColor() const;

    void SetColor(const std::string& _color);
};

class Parrot : public Animal {
private:
    std::optional<__int16> lexicon;
public:
    using Animal::Animal;
    Parrot (Owner _owner, std::string _name, const __int16& _age, const __int16& _lexicon) : Animal(std::move(_owner),
        std::move(_name), _age), lexicon(_lexicon) {};

    void MakeSound() const override;

    __int16 GetLexicon() const;

    void SetLexicon(const __int16& _lexicon);
};

class Fish : public Animal {
private:
    std::optional<__int16> avg_depth;
public:
    using Animal::Animal;
    Fish (Owner _owner, std::string _name, const __int16& _age, const __int16& _avg_depth) : Animal(std::move(_owner),
        std::move(_name), _age), avg_depth(_avg_depth) {};

    void MakeSound() const override;

    __int16 GetAvgDepth() const;

    void SetAvgDepth(const __int16& _avg_depth);
};

class Pig : public Animal {
private:
    std::optional<__int16> piglet_size;
    Pig (Owner _owner, std::string _name, const __int16& _age, const __int16& _piglet_size) : Animal(std::move(_owner),
        std::move(_name), _age), piglet_size(_piglet_size) {};
public:
    using Animal::Animal;

    void MakeSound() const override;

    __int16 GetPigletSize() const;

    void SetPigletSize(const __int16& _piglet_size);
};


#endif //ANIMALS_H