#include <iostream>
using namespace std;

// Nag define sa Student structure
struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    int numStudents;

    // Task 1: Ask user for number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();

    // Task 2: allocate array using pointers
    Student* ptr = new Student[numStudents];

    // Task 3: Input student info
    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.getline((ptr + i)->name, 50); // pointer arithmetic
        cout << "Age: ";
        cin >> (ptr + i)->age;
        cout << "Grade: ";
        cin >> (ptr + i)->grade;
        cin.ignore();
    }

    // Task 4 & 5: Display all records and show memory address
    cout << "\n=== Student Records ===\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "\nRecord " << i + 1 << ":\n";
        cout << "Memory Address: " << (ptr + i) << endl; // This line shows the memory address
        cout << "Name: " << (ptr + i)->name << endl;
        cout << "Age: " << (ptr + i)->age << endl;
        cout << "Grade: " << (ptr + i)->grade << endl;
    }

    
    delete[] ptr;

    return 0;
}
