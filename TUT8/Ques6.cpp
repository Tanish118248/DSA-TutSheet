#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class MaxHeap {
    vector<int> heap; 
public:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void insert(int key) {
        heap.push_back(key);
        int i = heap.size() - 1;
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    int getMax() {
        if (heap.empty())
            return -1;
        return heap[0];
    }

    int extractMax() {
        if (heap.size() <= 0)
            return -1;
        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return root;
    }

    void increaseKey(int i, int newValue) {
        heap[i] = newValue;
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        increaseKey(i, INT_MAX); 
        extractMax();           
    }

    void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;

    pq.insert(10);
    pq.insert(40);
    pq.insert(20);
    pq.insert(30);
    pq.insert(50);

    cout << "Priority Queue (Max-Heap): ";
    pq.display();
    cout << "Maximum: " << pq.getMax() << endl;
    cout << "Extracted Max: " << pq.extractMax() << endl;
    cout << "After extraction: ";
    pq.display();

    pq.increaseKey(1, 60);
    cout << "After increaseKey: ";
    pq.display();

    pq.deleteKey(2);
    cout << "After deleteKey: ";
    pq.display();

    return 0;
}


