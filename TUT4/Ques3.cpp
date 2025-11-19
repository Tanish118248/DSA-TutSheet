#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % MAX;
        size--;
        return val;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getSize() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int i = front;
        for (int cnt = 0; cnt < size; cnt++) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
void interleaveQueue(Queue &q) {
    int n = q.getSize();
    if (n % 2 != 0) {
        cout << "Queue must have even number of elements\n";
        return;
    }

    int half = n / 2;
    Queue firstHalf;
    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue()); 
        q.enqueue(q.dequeue());       
    }
}

int main() {
    Queue q;

    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    cout << "Original Queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}



