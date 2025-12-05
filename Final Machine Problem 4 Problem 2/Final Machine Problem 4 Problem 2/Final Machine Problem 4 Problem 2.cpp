#include <iostream>
using namespace std;

// Partition function for Quick Sort
int partitionArray(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            // Swap A[i] and A[j]
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // Swap pivot to correct position
    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;

    // Show current partition
    cout << "Partition (" << low << "," << high << ") pivot = "
        << pivot << " => [";
    for (int k = low; k <= high; k++)
        cout << A[k] << (k < high ? ", " : "");
    cout << "]\n";

    return i + 1;
}

// Quick Sort function
void quickSort(int A[], int low, int high) {
    if (low < high) {
        int p = partitionArray(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Dynamic array allocation
    int* A = new int[n];

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    quickSort(A, 0, n - 1);

    cout << "\nFinal Sorted Array: [";
    for (int i = 0; i < n; i++)
        cout << A[i] << (i < n - 1 ? ", " : "");
    cout << "]\n";

    delete[] A; // Free allocated memory
    return 0;
}
