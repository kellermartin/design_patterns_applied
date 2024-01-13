#include <iostream>
#include <vector>

// Component Interface
class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

// Leaf (Individual Object)
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// Composite (Composition of Objects)
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void remove(Component* component) {
        // Remove component logic
        // ...
    }

    void operation() const override {
        std::cout << "Composite operation" << std::endl;
        for (const Component* component : children) {
            component->operation();
        }
    }
};

int main() {
    // Client code using the Composite Pattern

    // Create individual objects
    Leaf leaf1, leaf2;

    // Create a composite object and add individual objects
    Composite composite;
    composite.add(&leaf1);
    composite.add(&leaf2);

    // Perform operations on both individual and composite objects uniformly
    leaf1.operation();
    std::cout << "--------" << std::endl;
    composite.operation();

    return 0;
}
