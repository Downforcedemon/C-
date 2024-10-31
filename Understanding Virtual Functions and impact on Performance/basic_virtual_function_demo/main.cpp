#include "Animal.h"
#include "Dog.cpp"
#include "Cat.cpp"



int main() {


    Dog dog;
    Cat cat;

    Animal* animalPtr = &dog;
    animalPtr->makeSound();

    animalPtr = &cat;
    animalPtr->makeSound();

    return 0;
}
