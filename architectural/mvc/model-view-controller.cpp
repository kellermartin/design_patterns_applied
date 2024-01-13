#include <iostream>
#include <vector>
#include <string>

// Model
class Model {
private:
    std::vector<std::string> data;

public:
    void addData(const std::string& item) {
        data.push_back(item);
    }

    const std::vector<std::string>& getData() const {
        return data;
    }
};

// View
class View {
public:
    void displayData(const std::vector<std::string>& data) const {
        std::cout << "View: Displaying data" << std::endl;
        for (const auto& item : data) {
            std::cout << item << std::endl;
        }
    }
};

// Controller
class Controller {
private:
    Model model;
    View view;

public:
    void addItem(const std::string& item) {
        model.addData(item);
    }

    void updateView() {
        const std::vector<std::string>& data = model.getData();
        view.displayData(data);
    }
};

int main() {
    // Client code using the Model-View-Controller (MVC) Pattern

    // Create a controller
    Controller controller;

    // Add items to the model
    controller.addItem("Item 1");
    controller.addItem("Item 2");
    controller.addItem("Item 3");

    // Update the view to display the data
    controller.updateView();

    return 0;
}
