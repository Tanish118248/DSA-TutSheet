#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    Node* n1 = new Node{2, NULL};
    Node* n2 = new Node{4, NULL};
    Node* n3 = new Node{6, NULL};
    Node* n4 = new Node{7, NULL};
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n1; 
    cout << (isCircular(n1) ? "True" : "False") << endl;
    return 0;
}
