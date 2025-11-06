#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node *tail = head;
    while (tail->next) tail = tail->next;

    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node *n1 = new Node{'A', NULL, NULL};
    Node *n2 = new Node{'B', n1, NULL};
    Node *n3 = new Node{'C', n2, NULL};
    Node *n4 = new Node{'B', n3, NULL};
    Node *n5 = new Node{'A', n4, NULL};
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;

    if (isPalindrome(n1))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}
