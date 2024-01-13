#include <iostream>
#include <string>

// Target Interface
class Target {
public:
    virtual void request() const = 0;
    virtual ~Target() = default;
};

// Adaptee (Existing Class)
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Specific Request from Adaptee" << std::endl;
    }
};

// Adapter
class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adpt) : adaptee(adpt) {}

    void request() const override {
        if (adaptee) {
            adaptee->specificRequest();
        }
    }
};

int main() {
    // Client code using the Adapter Pattern

    // Create an Adaptee instance
    Adaptee adaptee;

    // Create an Adapter and pass the Adaptee instance
    Adapter adapter(&adaptee);

    // Use the Target interface (unknown to the client)
    adapter.request();

    return 0;
}
