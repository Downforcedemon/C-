// VirtualAnimal.h
#ifndef VIRTUAL_ANIMAL_H
#define VIRTUAL_ANIMAL_H

#include <iostream>

class VirtualAnimal {
public:
    virtual void makeSound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }
    virtual ~VirtualAnimal() = default;
};

class VirtualDog : public VirtualAnimal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

#endif // VIRTUAL_ANIMAL_H
