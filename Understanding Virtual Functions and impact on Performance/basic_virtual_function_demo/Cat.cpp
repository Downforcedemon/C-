#include <iostream>
#include "Animal.cpp"

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow" << std::endl;
    }
};
