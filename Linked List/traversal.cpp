#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

int main() {
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    printList(head);
    return 0;
}