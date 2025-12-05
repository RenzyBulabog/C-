#include <iostream>
#include <cstring>
using namespace std;

struct Product {
    int id;
    char name[30];
    double price;
};

// Function to display product details using pointer to struct
void display(Product* p) {
    cout << "\n--- Product Details ---\n";
    cout << "ID: " << p->id << "     Address: " << &(p->id) << endl;
    cout << "Name: " << p->name << "  Address: " << &(p->name) << endl;
    cout << "Price: " << p->price << " Address: " << &(p->price) << endl;
}

int main() {
    Product products[5];  // fixed-size array of 5 products

    cout << "Enter details of 5 products:\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i + 1 << " ID: ";
        cin >> products[i].id;
        cin.ignore(); // clear buffer

        cout << "Product " << i + 1 << " Name: ";
        cin.getline(products[i].name, 30);

        cout << "Product " << i + 1 << " Price: ";
        cin >> products[i].price;
    }

    // Displaying all products
    cout << "\n==============================";
    cout << "\n Displaying All Product Data";
    cout << "\n==============================\n";

    for (int i = 0; i < 5; i++) {
        display(&products[i]);   // pass address of each product
    }

    return 0;
}
