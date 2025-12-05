#include <iostream>
using namespace std;

// Define Employee structure
struct Employee {
    char name[50];
    double salary;
};

int main() {
    // Task 1: Declare array of 3 employees
    Employee employees[3];

    // Task 2: Create a pointer to the first element
    Employee* ptr = employees;

    // Task 3: Input all employee records using pointer arithmetic
    cout << "=== Enter Employee Details ===\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        cout << "Enter Name: ";
        cin.getline((ptr + i)->name, 50);
        cout << "Enter Salary: ";
        cin >> (ptr + i)->salary;
        cin.ignore(); 

        cout << "Memory Address of Record " << i + 1 << ": " << (ptr + i) << endl;
    }

    // Task 4: Increase each employee's salary by 10% using pointer only
    for (int i = 0; i < 3; i++) {
        (ptr + i)->salary *= 1.10;  // increase by 10%
    }

    // Task 5: Display updated records using pointer arithmetic
    cout << "\n=== Updated Employee Records (After 10% Increase) ===\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        cout << "Address: " << (ptr + i) << endl;
        cout << "Name: " << (ptr + i)->name << endl;
        cout << "Updated Salary: " << (ptr + i)->salary << endl;
    }

    return 0;
}
