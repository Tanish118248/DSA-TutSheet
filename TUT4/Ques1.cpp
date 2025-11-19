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

    bool isFull() {
        return rear == MAX - 1;
    }
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1 ) front = 0; 
        arr[++rear] = val; 
    }

 
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1; 
        }
        return arr[front++]; }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is: " << q.peek() << endl; 

    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Front element is: " << q.peek() << endl; 

    return 0;
}
