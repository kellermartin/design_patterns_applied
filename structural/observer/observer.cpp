#include <iostream>
#include <vector>

// Abstract Observer
class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
    void setObserverId(int id){_observerId = id;};
protected:
    int _observerId;
};

// Concrete Observer
class ConcreteObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Received message: " << message << " for observer with id: " << _observerId  << std::endl;
    }
};

// Subject
class Subject {
private:
    std::vector<Observer*> observers;
    std::string state;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // Remove observer logic
        // ...
    }

    void setState(const std::string& newState) {
        state = newState;
        notifyObservers();
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(state);
        }
    }
};

int main() {
    // Client code using the Observer Pattern

    // Create subject and observers
    Subject subject;
    ConcreteObserver observer1, observer2;
    observer1.setObserverId(1);
    observer2.setObserverId(2);

    // Attach observers to the subject
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // Set the state of the subject, which triggers notifications to observers
    subject.setState("New State");

    return 0;
}
