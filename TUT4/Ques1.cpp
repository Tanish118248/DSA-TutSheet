#include <iostream>
using namespace std;
#define MAX 1000
class Queue {
    int front, rear;
    int arr[MAX];
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == MAX - 1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Add an element to the queue
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1 ) front = 0; // Initialize front on first enqueue
        arr[++rear] = val; // Increment rear and add the new element
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1; // Return -1 to indicate underflow
        }
        return arr[front++]; // Return the front element and increment front
    }

    // Get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate empty queue
        }
        return arr[front]; // Return the front element without removing it
    }
};
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is: " << q.peek() << endl; // Should print 10

    cout << "Dequeued: " << q.dequeue() << endl; // Should print 10
    cout << "Front element is: " << q.peek() << endl; // Should print 20

    return 0;
}
