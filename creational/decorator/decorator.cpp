#include <iostream>
#include <memory>

// Component Interface
class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

// Concrete Component
class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "Concrete Component operation" << std::endl;
    }
};

// Decorator Base Class
class Decorator : public Component {
protected:
    std::unique_ptr<Component> component;

public:
    Decorator(std::unique_ptr<Component> comp) : component(std::move(comp)) {}

    void operation() const override {
        if (component) {
            component->operation();
        }
    }
};

// Concrete Decorator A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(std::unique_ptr<Component> comp) : Decorator(std::move(comp)) {}

    void operation() const override {
        Decorator::operation();
        addBehaviorA();
    }

private:
    void addBehaviorA() const {
        std::cout << "Additional behavior from Concrete Decorator A" << std::endl;
    }
};

// Concrete Decorator B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(std::unique_ptr<Component> comp) : Decorator(std::move(comp)) {}

    void operation() const override {
        Decorator::operation();
        addBehaviorB();
    }

private:
    void addBehaviorB() const {
        std::cout << "Additional behavior from Concrete Decorator B" << std::endl;
    }
};

int main() {
    // Client code using the Decorator Pattern

    // Create a Concrete Component
    std::unique_ptr<Component> component = std::make_unique<ConcreteComponent>();

    // Wrap the component with Decorators
    std::unique_ptr<Component> decoratedComponentA = std::make_unique<ConcreteDecoratorA>(std::move(component));
    std::unique_ptr<Component> decoratedComponentB = std::make_unique<ConcreteDecoratorB>(std::move(decoratedComponentA));

    // Perform operations on the decorated component
    decoratedComponentB->operation();

    return 0;
}
