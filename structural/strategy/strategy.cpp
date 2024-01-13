#include <iostream>
#include <memory>

// Strategy Interface
class Strategy {
public:
    virtual void execute() const = 0;
    virtual ~Strategy() = default;
};

// Concrete Strategy A
class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing Strategy A" << std::endl;
    }
};

// Concrete Strategy B
class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing Strategy B" << std::endl;
    }
};

// Context
class Context {
private:
    std::unique_ptr<Strategy> strategy;

public:
    Context(std::unique_ptr<Strategy> strat) : strategy(std::move(strat)) {}

    void setStrategy(std::unique_ptr<Strategy> strat) {
        strategy = std::move(strat);
    }

    void executeStrategy() const {
        if (strategy) {
            strategy->execute();
        }
    }
};

int main() {
    // Client code using the Strategy Pattern

    // Create strategies
    std::unique_ptr<Strategy> strategyA = std::make_unique<ConcreteStrategyA>();
    std::unique_ptr<Strategy> strategyB = std::make_unique<ConcreteStrategyB>();

    // Create context with Strategy A
    Context context(std::move(strategyA));
    context.executeStrategy();

    std::cout << "--------" << std::endl;

    // Change context's strategy to Strategy B
    context.setStrategy(std::move(strategyB));
    context.executeStrategy();

    return 0;
}
