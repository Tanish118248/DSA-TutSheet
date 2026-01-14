#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};
void countAndDelete(Node* &head, int key) {
    int count = 0;
    Node *temp = head, *prev = NULL;
    while (temp) {
        if (temp->data == key) {
            count++;
            if (temp == head) {
                head = head->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    cout << "Count: " << count << endl;

    cout << "Updated List: ";
    temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node{1, new Node{2, new Node{1, new Node{2, new Node{1, new Node{3, new Node{1, NULL}}}}}}};
    countAndDelete(head, 1);
    return 0;
}
