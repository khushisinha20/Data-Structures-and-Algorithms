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

Node* deleteTail(Node* head) {
    if (head == NULL)
        return NULL;
    
    if (head -> next == NULL) {
        delete head;
        return NULL;
    }
    
    Node* curr = head;
        
    while (curr -> next -> next != NULL) 
        curr = curr -> next;
        
    delete (curr -> next);
    curr -> next = NULL;
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

int main() {
    Node* head = NULL;
    head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head = deleteTail(head);
    printList(head);
    return 0;
}