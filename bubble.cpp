#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* a = new int[n];   // Dynamic array

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    // Bubble Sort
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    delete[] a;  // Free memory

    return 0;
}