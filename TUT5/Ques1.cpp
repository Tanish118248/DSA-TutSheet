#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertAtBeginning(int val) {
    Node *newNode = new Node{val, head};
    head = newNode;
    cout << "Inserted " << val << " at beginning.\n";
}

void insertAtEnd(int val) {
    Node *newNode = new Node{val, NULL};
    if (!head) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    cout << "Inserted " << val << " at end.\n";
}

void insertAfter(int key, int val) {
    Node *temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) {
        cout << "Key not found.\n";
        return;
    }
    Node *newNode = new Node{val, temp->next};
    temp->next = newNode;
    cout << "Inserted " << val << " after " << key << ".\n";
}

void deleteFromBeginning() {
    if (!head) return;
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "Deleted from beginning.\n";
}

void deleteFromEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = NULL;
        cout << "Deleted from end.\n";
        return;
    }
    Node *temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    cout << "Deleted from end.\n";
}

void deleteSpecific(int key) {
    if (!head) return;
    if (head->data == key) {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted " << key << ".\n";
        return;
    }
    Node *temp = head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (!temp->next) {
        cout << "Node not found.\n";
        return;
    }
    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
    cout << "Deleted " << key << ".\n";
}

void searchNode(int key) {
    Node *temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            cout << "Found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found.\n";
}

void display() {
    Node *temp = head;
    cout << "List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int ch, val, key;
    do {
        cout << "\n1.InsertBeg 2.InsertEnd 3.InsertAfter 4.DelBeg 5.DelEnd 6.DelSpecific 7.Search 8.Display 0.Exit\n";
        cin >> ch;
        switch(ch){
            case 1: cout<<"Val:";cin>>val;insertAtBeginning(val);break;
            case 2: cout<<"Val:";cin>>val;insertAtEnd(val);break;
            case 3: cout<<"Key & Val:";cin>>key>>val;insertAfter(key,val);break;
            case 4: deleteFromBeginning();break;
            case 5: deleteFromEnd();break;
            case 6: cout<<"Val:";cin>>key;deleteSpecific(key);break;
            case 7: cout<<"Val:";cin>>key;searchNode(key);break;
            case 8: display();break;
        }
    }while(ch!=0);
    return 0;
}



