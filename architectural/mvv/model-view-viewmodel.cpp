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

// ViewModel
class ViewModel {
private:
    Model model;

public:
    void addItem(const std::string& item) {
        model.addData(item);
    }

    const std::vector<std::string>& getData() const {
        return model.getData();
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

// Main Application (Controller)
int main() {
    // Client code using the Model-View-ViewModel (MVVM) Pattern

    // Create a ViewModel
    ViewModel viewModel;

    // Add items to the ViewModel
    viewModel.addItem("Item 1");
    viewModel.addItem("Item 2");
    viewModel.addItem("Item 3");

    // Create a View and display the data from the ViewModel
    View view;
    view.displayData(viewModel.getData());

    return 0;
}
