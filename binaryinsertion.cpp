#include <iostream>
using namespace std;

// Function to perform binary search to find the position to insert
int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Function to perform Binary Insertion Sort
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Find location where key should be inserted
        int loc = binarySearch(arr, key, 0, j);

        // Shift elements to make room for key
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Display array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    binaryInsertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
