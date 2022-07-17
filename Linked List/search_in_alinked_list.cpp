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

int searchList(Node* head, int key) {
    int position = 1;
    Node* curr = head;
    while (curr != NULL) {
        if (curr -> data == key)
            return position;
        ++position;
        curr = curr -> next;
    }
    return -1;
}

int main() {
    Node* head = new Node(10);  
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    cout << searchList(head, 20);
    return 0;
}