#include <iostream>
#include <cstring>
using namespace std;

struct Employee {
    char name[50];
    double salary;
};

int main() {
    Employee employees[3];   // 1. Declare array of 3 employees
    Employee* ptr = employees; // 2. Pointer points to first element

    cout << "=== INPUT EMPLOYEE RECORDS ===\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nEmployee " << (i + 1) << ":\n";

        cout << "Enter name: ";
        cin.ignore(i == 0 ? 0 : 1000, '\n'); // ignore leftover newline
        cin.getline((ptr + i)->name, 50);

        cout << "Enter salary: ";
        cin >> (ptr + i)->salary;
    }

    cout << "\n=== DISPLAY WITH ADDRESSES ===\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nEmployee " << (i + 1) << ":\n";
        cout << "Name: " << (ptr + i)->name << endl;
        cout << "Salary: " << (ptr + i)->salary << endl;
        cout << "Address: " << (ptr + i) << endl;
    }

    // 4. Increase salary by 10% using ONLY pointer arithmetic
    Employee* p = employees; // temp pointer
    for (int i = 0; i < 3; i++) {
        p->salary *= 1.10; // increase by 10%
        p++;               // move pointer to next employee
    }

    cout << "\n=== UPDATED RECORDS (After 10% Increase) ===\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nEmployee " << (i + 1) << ":\n";
        cout << "Name: " << employees[i].name << endl;
        cout << "Updated Salary: " << employees[i].salary << endl;
    }

    return 0;
}
