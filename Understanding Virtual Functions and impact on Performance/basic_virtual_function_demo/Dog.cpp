#include <iostream>
#include "Animal.cpp"

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};
