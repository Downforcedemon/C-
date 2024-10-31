#ifndef ANIMAL_H
#define ANIMAL_H



class Animal {
public:
    virtual void makeSound() const;  // Declaration only
    virtual ~Animal() = default;     // Destructor declaration
};

#endif // ANIMAL_H
