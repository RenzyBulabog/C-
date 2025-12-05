#include <iostream>
using namespace std;

// Merge two subarrays A[left..mid] and A[mid+1..right]
void mergeArrays(int A[], int left, int mid, int right) {
    cout << "Merge: left=" << left << " mid=" << mid
        << " right=" << right << "\n";

    int nL = mid - left + 1;
    int nR = right - mid;

    // Dynamic arrays for left and right subarrays
    int* L = new int[nL];
    int* R = new int[nR];

    for (int i = 0; i < nL; i++)
        L[i] = A[left + i];
    for (int i = 0; i < nR; i++)
        R[i] = A[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < nL && j < nR) {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < nL)
        A[k++] = L[i++];
    while (j < nR)
        A[k++] = R[j++];

    // Display merged array
    cout << "After merge: [";
    for (int x = left; x <= right; x++)
        cout << A[x] << (x < right ? ", " : "");
    cout << "]\n";

    // Free dynamic memory
    delete[] L;
    delete[] R;
}

// Merge Sort function
void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        cout << "Divide: [" << left << "," << right
            << "] into [" << left << "," << mid << "] and ["
            << mid + 1 << "," << right << "]\n";

        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        mergeArrays(A, left, mid, right);
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

    mergeSort(A, 0, n - 1);

    cout << "\nFinal Sorted Array: [";
    for (int i = 0; i < n; i++)
        cout << A[i] << (i < n - 1 ? ", " : "");
    cout << "]\n";

    delete[] A; // Free allocated memory
    return 0;
}
