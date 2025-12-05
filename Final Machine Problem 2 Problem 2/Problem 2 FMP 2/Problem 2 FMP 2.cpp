#include <iostream>
using namespace std;

// Define Product structure
struct Product {
    int id;
    char name[30];
    double price;
};

// Task 2: Function to display products
void display(Product* p) {
    cout << "\n--- Product Information ---\n";
    cout << "Product Address: " << p << endl;
    cout << "ID: " << p->id << " (Address: " << &(p->id) << ")\n";
    cout << "Name: " << p->name << " (Address: " << &(p->name) << ")\n";
    cout << "Price: " << p->price << " (Address: " << &(p->price) << ")\n";
}

int main() {
    // Task 1: Declare fixed-sized array of 5 products
    Product products[5];

    // Task 3: Input details for all products
    cout << "=== Enter Product Details ===\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << "Enter ID: ";
        cin >> products[i].id;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(products[i].name, 30);
        cout << "Enter Price: ";
        cin >> products[i].price;
        cin.ignore();
    }

    // Task 4: Pass address of each product to display function
    cout << "\n=== Displaying All Products ===\n";
    for (int i = 0; i < 5; i++) {
        display(&products[i]); // pass address to display
    }

    return 0;
}
