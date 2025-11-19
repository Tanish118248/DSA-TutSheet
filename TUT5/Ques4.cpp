#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* reverseList(Node *head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(Node *head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node *head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}};
    cout << "Original: ";
    display(head);
    head = reverseList(head);
    cout << "Reversed: ";
    display(head);
    return 0;
}
