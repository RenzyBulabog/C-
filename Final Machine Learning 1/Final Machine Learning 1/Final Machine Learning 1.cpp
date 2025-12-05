#include <iostream>
#include <string>
using namespace std;


// Represents each node in the Binary search Tree (BST). defines each node record
struct Student {
    int id;              // Student ID (used as BST key)
    string name;         // Student name
    float grade;         // Student grade
    Student* left;       // Pointer to left child
    Student* right;      // Pointer to right child
};


// This function create and returns a new node
Student* createStudent(int id, string name, float grade) {
    Student* newStudent = new Student();
    newStudent->id = id;
    newStudent->name = name;
    newStudent->grade = grade;
    newStudent->left = newStudent->right = nullptr;
    return newStudent;
}


// Inserts a new student record into the BST
Student* insert(Student* root, int id, string name, float grade) {
    // If the tree is empty, return a new node
    if (root == nullptr)
        return createStudent(id, name, grade);

    // Add a new student record into the tree in sorted order by ID
    if (id < root->id)
        root->left = insert(root->left, id, name, grade);
    else if (id > root->id)
        root->right = insert(root->right, id, name, grade);
    else
        cout << "Student ID already exists!\n"; // No duplicate IDs allowed

    return root;
}


// Searches for a student using their ID in the BST.
void search(Student* root, int id) {
    if (root == nullptr) {
        cout << "Student not found.\n";
        return;
    }
    // looks for a student ID
    if (id == root->id)
        cout << "Student Found: " << root->name << " (Grade: " << root->grade << ")\n";
    else if (id < root->id)
        search(root->left, id);
    else
        search(root->right, id);
}


// Used in the deletion process to find the smallest value in a subtree. find the smallest ID node
Student* findMin(Student* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}


// Deletes a student record by ID while keeping binary search tree rules correct.
Student* deleteStudent(Student* root, int id) {
    if (root == nullptr)
        return root; // Empty tree

    // Find the node to delete
    if (id < root->id)
        root->left = deleteStudent(root->left, id);
    else if (id > root->id)
        root->right = deleteStudent(root->right, id);
    else {
        // Node found — handle 3 cases:
        // Case 1: Node with only right child or no child
        if (root->left == nullptr) {
            Student* temp = root->right;
            delete root;
            cout << "Student deleted successfully.\n";
            return temp;
        }
        // Case 2: Node with only left child
        else if (root->right == nullptr) {
            Student* temp = root->left;
            delete root;
            cout << "Student deleted successfully.\n";
            return temp;
        }

        // Case 3: Node with two children
        // Find smallest node in right subtree
        Student* temp = findMin(root->right);
        // Copy data from that node
        root->id = temp->id;
        root->name = temp->name;
        root->grade = temp->grade;
        // Delete the duplicate node from right subtree
        root->right = deleteStudent(root->right, temp->id);
    }
    return root;
}


// INORDER (Left, Root, Right) - shows records sorted by ID
void inorder(Student* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << "[" << root->id << " | " << root->name << " | " << root->grade << "] ";
        inorder(root->right);
    }
}

// PREORDER (Root, Left, Right)
void preorder(Student* root) {
    if (root != nullptr) {
        cout << "[" << root->id << " | " << root->name << " | " << root->grade << "] ";
        preorder(root->left);
        preorder(root->right);
    }
}

// POSTORDER (Left, Right, Root)
void postorder(Student* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << "[" << root->id << " | " << root->name << " | " << root->grade << "] ";
    }
}


// Creates the root pointer for the BST (root = nullptr)
// int choice, stores my menu option
int main() {
    Student* root = nullptr; // Initialize BST as empty
    int choice, id;
    string name;
    float grade;

    // this part displays the menu every loop
    do {
        // Display menu options
        cout << "\n=== Student Records using BST ===\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Search Student by ID\n";
        cout << "3. Delete Student by ID\n";
        cout << "4. Display Inorder\n";
        cout << "5. Display Preorder\n";
        cout << "6. Display Postorder\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Insert new student
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name; // (Note: this will stop at spaces)
            cout << "Enter Grade: ";
            cin >> grade;
            root = insert(root, id, name, grade);
            break;

        case 2:
            // Search by ID
            cout << "Enter ID: ";
            cin >> id;
            search(root, id);
            break;

        case 3:
            // Delete by ID
            cout << "Enter ID: ";
            cin >> id;
            root = deleteStudent(root, id);
            break;

        case 4:
            // Display Inorder
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << "\n";
            break;

        case 5:
            // Display Preorder
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << "\n";
            break;

        case 6:
            // Display Postorder
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << "\n";
            break;

        case 7:
            // Exit program
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}