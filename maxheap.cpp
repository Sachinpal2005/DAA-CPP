#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();

        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    void printHeap() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);

    cout << "Heap: ";
    h.printHeap();

    cout << "Max element: " << h.getMax() << endl;

    h.deleteMax();

    cout << "After deleting max: ";
    h.printHeap();

    return 0;
}