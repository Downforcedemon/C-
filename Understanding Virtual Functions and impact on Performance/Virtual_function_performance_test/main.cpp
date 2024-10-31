#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "VirtualAnimal.h"
#include "NonVirtualAnimal.h"

int main() {
    const int numAnimals = 1000000;

    // Open a file to write the results
    std::ofstream outFile("results.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }

    // Vector of base class pointers for virtual animals
    std::vector<VirtualAnimal*> virtualAnimals;
    for (int i = 0; i < numAnimals; ++i) {
        virtualAnimals.push_back(new VirtualDog());
    }

    // Measure time for virtual function calls
    auto start = std::chrono::high_resolution_clock::now();
    for (auto animal : virtualAnimals) {
        animal->makeSound();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> virtualDuration = end - start;
    outFile << "Virtual function call time: " << virtualDuration.count() << " seconds\n";
    std::cout << "Virtual function call time: " << virtualDuration.count() << " seconds\n";

    // Vector of non-virtual animals
    std::vector<NonVirtualDog> nonVirtualAnimals(numAnimals);

    // Measure time for non-virtual function calls
    start = std::chrono::high_resolution_clock::now();
    for (auto& animal : nonVirtualAnimals) {
        animal.makeSound();
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> nonVirtualDuration = end - start;
    outFile << "Non-virtual function call time: " << nonVirtualDuration.count() << " seconds\n";
    std::cout << "Non-virtual function call time: " << nonVirtualDuration.count() << " seconds\n";

    // Cleanup virtual animals
    for (auto animal : virtualAnimals) {
        delete animal;
    }

    // Close the file
    outFile.close();

    return 0;
}
