#include <iostream>

class Singleton {
private:
    // Private constructor to prevent instantiation
    Singleton() {}

public:
    // Function to get the instance of the Singleton class
    static Singleton& getInstance() {
        static Singleton instance; // Guaranteed to be created only once
        return instance;
    }

    // Other member functions and variables can be added here

    // Example function
    void showMessage() {
        std::cout << "Singleton Pattern Example" << std::endl;
    }
};

int main() {
    // Attempting to create multiple instances
    Singleton& firstInstance = Singleton::getInstance();
    Singleton& secondInstance = Singleton::getInstance();

    // Both instances should be the same
    std::cout << "Are both instances the same? " << (&firstInstance == &secondInstance ? "Yes" : "No") << std::endl;

    // Using the singleton instance
    firstInstance.showMessage();

    return 0;
}
