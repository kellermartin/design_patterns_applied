#include <iostream>
#include <memory>

// Abstract Products
class AbstractProductA {
public:
    virtual void display() const = 0;
    virtual ~AbstractProductA() = default;
};

class AbstractProductB {
public:
    virtual void showInfo() const = 0;
    virtual ~AbstractProductB() = default;
};

// Concrete Products for Family 1
class ProductA1 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "Product A1" << std::endl;
    }
};

class ProductB1 : public AbstractProductB {
public:
    void showInfo() const override {
        std::cout << "Product B1" << std::endl;
    }
};

// Concrete Products for Family 2
class ProductA2 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "Product A2" << std::endl;
    }
};

class ProductB2 : public AbstractProductB {
public:
    void showInfo() const override {
        std::cout << "Product B2" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() = 0;
    virtual ~AbstractFactory() = default;
};

// Concrete Factory for Family 1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() override {
        return std::make_unique<ProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() override {
        return std::make_unique<ProductB1>();
    }
};

// Concrete Factory for Family 2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() override {
        return std::make_unique<ProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() override {
        return std::make_unique<ProductB2>();
    }
};

int main() {
    // Client code using the Abstract Factory Pattern

    // Create products through Factory 1
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractProductA> productA1 = factory1->createProductA();
    std::unique_ptr<AbstractProductB> productB1 = factory1->createProductB();

    productA1->display();
    productB1->showInfo();

    std::cout << "--------" << std::endl;

    // Create products through Factory 2
    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
    std::unique_ptr<AbstractProductA> productA2 = factory2->createProductA();
    std::unique_ptr<AbstractProductB> productB2 = factory2->createProductB();

    productA2->display();
    productB2->showInfo();

    return 0;
}
