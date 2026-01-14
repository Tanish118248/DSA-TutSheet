#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

void findMiddle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data << endl;
}

int main() {
    Node *head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}};
    findMiddle(head);
    return 0;
}

