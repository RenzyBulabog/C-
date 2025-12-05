#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& A) {
    int n = A.size();
    bool swapped;

    for (int pass = 1; pass <= n - 1; pass++) {
        swapped = false;

        cout << "\nPass " << pass << ": ";

        for (int j = 0; j < n - pass; j++) {
            if (A[j] > A[j + 1]) {
                cout << A[j] << " > " << A[j + 1] << " swap; ";

                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;

                swapped = true;
            }
        }

        cout << " Array now: [";
        for (int k = 0; k < n; k++)
            cout << A[k] << (k < n - 1 ? ", " : "");
        cout << "]";

        if (!swapped) {
            cout << "\nNo swaps — DONE.\n";
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    bubbleSort(A);

    cout << "\nFinal Sorted Array: [";
    for (int i = 0; i < n; i++)
        cout << A[i] << (i < n - 1 ? ", " : "");
    cout << "]\n";

    return 0;
}
