#include <iostream>

class MyClass {
public:
    // Overload the 'new' operator
    void* operator new(std::size_t size){
    std::cout << "Custom new called\n";
    return new MyClass;
    }
    MyClass() {
        std::cout << "Constructor called\n";
    }
};

int main() {
    MyClass* obj = new MyClass();
    delete obj;
    return 0;
}
