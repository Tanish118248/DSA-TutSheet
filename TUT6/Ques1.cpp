#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int val, int after = -1) {
    Node* newNode = new Node{val, NULL};
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }

    if (after == -1) { 
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    } else { 
        Node* temp = head;
        do {
            if (temp->data == after) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << after << " not found.\n";
    }
}

void deleteNode(int key) {
    if (!head) return;

    Node *curr = head, *prev = NULL;
    do {
        if (curr->data == key) {
            if (curr == head) {
                Node* last = head;
                while (last->next != head) last = last->next;
                head = head->next;
                last->next = head;
                delete curr;
                return;
            } else {
                prev->next = curr->next;
                delete curr;
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    cout << "Node not found.\n";
}

void search(int key) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Not found.\n";
}

void display() {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int ch, val, after;
    do {
        cout << "\n1.Insert 2.Delete 3.Search 4.Display 0.Exit\n";
        cin >> ch;
        switch(ch){
            case 1: cout << "Enter value: "; cin >> val;
                    cout << "Enter node after which to insert (-1 for end): ";
                    cin >> after; insert(val, after); break;
            case 2: cout << "Value to delete: "; cin >> val; deleteNode(val); break;
            case 3: cout << "Search value: "; cin >> val; search(val); break;
            case 4: display(); break;
        }
    } while(ch!=0);
    return 0;
}
