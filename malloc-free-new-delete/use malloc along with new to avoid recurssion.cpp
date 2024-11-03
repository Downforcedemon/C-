#include <iostream>
#include <cstdlib> // for malloc and free

class MyClass {
public:
    // Fixed version of 'operator new'
    void* operator new(std::size_t size) {
        std::cout << "Custom new called\n";
        return std::malloc(size); // Allocate raw memory without calling constructors
    }
    
    // Custom delete to match the custom new
    void operator delete(void* ptr) {
        std::cout << "Custom delete called\n";
        std::free(ptr); // Free the raw memory
    }
    
    MyClass() {
        std::cout << "Constructor called\n";
    }
    
    ~MyClass() {
        std::cout << "Destructor called\n";
    }
};

int main() {
    MyClass* obj = new MyClass(); // Uses the custom 'new'
    delete obj; // Uses the custom 'delete'
    return 0;
}
