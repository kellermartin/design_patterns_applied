#include <iostream>
#include <memory>

// Context
class Context;

// Abstract State
class State {
public:
    virtual void handle(Context& context) = 0;
    virtual ~State() = default;
};

// Concrete State A
class ConcreteStateA : public State {
public:
    void handle(Context& context) override;
};

// Concrete State B
class ConcreteStateB : public State {
public:
    void handle(Context& context) override;
};

// Context
class Context {
private:
    std::unique_ptr<State> currentState;

public:
    void setState(std::unique_ptr<State> newState) {
        currentState = std::move(newState);
    }

    void request() {
        if (currentState) {
            currentState->handle(*this);
        }
    }
};

// Concrete State A Implementation
void ConcreteStateA::handle(Context& context) {
    std::cout << "Handling request in State A, transitioning to State B." << std::endl;
    context.setState(std::make_unique<ConcreteStateB>());
}

// Concrete State B Implementation
void ConcreteStateB::handle(Context& context) {
    std::cout << "Handling request in State B, transitioning to State A." << std::endl;
    context.setState(std::make_unique<ConcreteStateA>());
}

int main() {
    // Client code using the State Pattern

    // Create a context with an initial state (State A)
    Context context;
    context.setState(std::make_unique<ConcreteStateA>());

    // Perform requests, causing state transitions
    context.request();
    context.request();
    context.request();

    return 0;
}
