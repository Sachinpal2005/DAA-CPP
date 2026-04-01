#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    // Helper function to get parent index
    int parent(int i) { return (i - 1) / 2; }
    // Helper function to get left child index
    int left(int i) { return 2 * i + 1; }
    // Helper function to get right child index
    int right(int i) { return 2 * i + 2; }

    // Heapify down (used after deletion)
    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify up (used after insertion)
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Insert a new element
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Extract minimum element
    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return root;
    }

    // Display heap elements
    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    cout << "Heap elements: ";
    h.display();

    cout << "Extracted Min: " << h.extractMin() << endl;

    cout << "Heap after extraction: ";
    h.display();

    return 0;
}
