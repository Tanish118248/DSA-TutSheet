#include <iostream>
using namespace std;

class CircularQueue {
    int arr[6];    
    int front, rear, size;

public:
    CircularQueue() {
        front = rear = -1;
        size = 6;  
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0; 
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0; 
        } else {
            front++;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(70);
    q.enqueue(80);

    q.display();

    cout << "Front element: " << q.getFront() << endl;

    return 0;
}

