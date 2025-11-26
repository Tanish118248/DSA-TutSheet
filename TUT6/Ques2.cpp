#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
};

void displayCircular(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data; 
    cout << endl;
}

int main() {
    Node* head = new Node{20, NULL};
    Node* n2 = new Node{100, NULL};
    Node* n3 = new Node{40, NULL};
    Node* n4 = new Node{80, NULL};
    Node* n5 = new Node{60, NULL};
    head->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = head;
    displayCircular(head);
    return 0;
}
