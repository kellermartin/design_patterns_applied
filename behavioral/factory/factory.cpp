#include <iostream>
#include <memory>

// Abstract Product
class Product {
public:
    virtual void display() const = 0;
    virtual ~Product() = default;
};

// Concrete Product A
class ConcreteProductA : public Product {
public:
    void display() const override {
        std::cout << "Product A" << std::endl;
    }
};

// Concrete Product B
class ConcreteProductB : public Product {
public:
    void display() const override {
        std::cout << "Product B" << std::endl;
    }
};

// Abstract Factory
class Factory {
public:
    virtual std::unique_ptr<Product> createProduct() = 0;
    virtual ~Factory() = default;
};

// Concrete Factory for Product A
class ConcreteFactoryA : public Factory {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProductA>();
    }
};

// Concrete Factory for Product B
class ConcreteFactoryB : public Factory {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProductB>();
    }
};

int main() {
    // Client code using the Factory Pattern

    // Creating a product through Factory A
    std::unique_ptr<Factory> factoryA = std::make_unique<ConcreteFactoryA>();
    std::unique_ptr<Product> productA = factoryA->createProduct();
    productA->display();

    std::cout << "--------" << std::endl;

    // Creating a product through Factory B
    std::unique_ptr<Factory> factoryB = std::make_unique<ConcreteFactoryB>();
    std::unique_ptr<Product> productB = factoryB->createProduct();
    productB->display();

    return 0;
}
