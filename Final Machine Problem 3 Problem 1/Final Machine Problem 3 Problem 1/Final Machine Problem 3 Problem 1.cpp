#include <iostream>
using namespace std;

// Structure definition
struct Student {
    char name[50];
    float grade;
};

int main() {
    int n;

    // 1. Ask user for number of students
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(); // clear leftover newline

    // 2. Dynamically allocate array of Students
    Student* ptr = new Student[n];

    // 3. Input each student's data using pointer arithmetic
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Name: ";
        cin.getline((ptr + i)->name, 50);

        cout << "Grade: ";
        cin >> (ptr + i)->grade;
        cin.ignore();
    }

    int failCount = 0;

    // 4. Display only passing students & count failing students
    cout << "\n=== Students Who Passed (Grade > 75) ===\n";
    for (int i = 0; i < n; i++) {
        if ((ptr + i)->grade > 75) {
            cout << "\nName: " << (ptr + i)->name << endl;
            cout << "Grade: " << (ptr + i)->grade << endl;
            cout << "Memory Address: " << (ptr + i) << endl;
        }
        else {
            failCount++;
        }
    }

    // Display fail count
    cout << "\nNumber of students who failed: " << failCount << endl;

    // Free dynamic memory
    delete[] ptr;

    return 0;
}
