#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // for std::setprecision and std::fixed

// Define a struct to hold information about each item
struct Item {
    std::string name;
    double price;
};

// Define a function to add an item to the cart
void addItem(std::vector<Item>& cart, const std::string& name, double price) {
    cart.push_back({ name, price });
}

// Define a function to print the receipt
void printReceipt(const std::vector<Item>& cart) {
    double total = 0.0;
    std::cout << std::fixed << std::setprecision(2); // set output precision to 2 decimal places
    std::cout << "-----------------------------\n";
    std::cout << "       SELF-SCAN RECEIPT      \n";
    std::cout << "-----------------------------\n";
    for (const auto& item : cart) {
        std::cout << std::left << std::setw(20) << item.name << std::right << std::setw(10) << item.price << "\n";
        total += item.price;
    }
    std::cout << "-----------------------------\n";
    std::cout << "TOTAL:                   " << std::setw(10) << total << "\n";
    std::cout << "-----------------------------\n";
}

int main() {
    std::vector<Item> cart; // vector to hold the items in the cart
    std::string name;
    double price;

    // Get input from the user until they are done scanning items
    while (true) {
        std::cout << "Enter item name (or 'done' to finish): ";
        std::getline(std::cin, name);
        if (name == "done") {
            break;
        }
        std::cout << "Enter price: ";
        std::cin >> price;
        std::cin.ignore(); // ignore newline character left in input stream after reading price
        addItem(cart, name, price);
    }

    // Print the receipt
    printReceipt(cart);

    return 0;
}
