#include <iostream>
#include <vector>
#include <memory>

// Command Interface
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Concrete Command
class ConcreteCommand : public Command {
private:
    // Reference to the receiver
    class Receiver {
    public:
        void performAction() {
            std::cout << "Receiver: Performing action" << std::endl;
        }
    };

    Receiver receiver;

public:
    void execute() override {
        receiver.performAction();
    }
};

// Invoker
class Invoker {
private:
    std::vector<std::unique_ptr<Command>> commands;

public:
    void addCommand(std::unique_ptr<Command> command) {
        commands.push_back(std::move(command));
    }

    void executeCommands() {
        for (const auto& command : commands) {
            command->execute();
        }
        commands.clear(); // Clear the commands after execution
    }
};

int main() {
    // Client code using the Command Pattern

    // Create commands
    std::unique_ptr<Command> command1 = std::make_unique<ConcreteCommand>();
    std::unique_ptr<Command> command2 = std::make_unique<ConcreteCommand>();

    // Create invoker
    Invoker invoker;

    // Add commands to the invoker
    invoker.addCommand(std::move(command1));
    invoker.addCommand(std::move(command2));

    // Execute the commands
    invoker.executeCommands();

    return 0;
}
