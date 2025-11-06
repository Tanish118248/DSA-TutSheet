#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *prev, *next;
};

int sizeDoubly(DNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

struct CNode {
    int data;
    CNode *next;
};

int sizeCircular(CNode* head) {
    if (!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    DNode* d1 = new DNode{10, NULL, NULL};
    d1->next = new DNode{20, d1, NULL};
    d1->next->next = new DNode{30, d1->next, NULL};
    cout << "Size of Doubly Linked List: " << sizeDoubly(d1) << endl;

    CNode* c1 = new CNode{1, NULL};
    CNode* c2 = new CNode{2, NULL};
    CNode* c3 = new CNode{3, NULL};
    c1->next = c2; c2->next = c3; c3->next = c1;
    cout << "Size of Circular Linked List: " << sizeCircular(c1) << endl;
    return 0;
}
