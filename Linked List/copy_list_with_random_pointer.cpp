//leetcode.com/problems/copy-list-with-random-pointer/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        Node* curr = head;
        Node* next = curr -> next;
        
        while (curr != nullptr) {
            next = curr -> next;
            Node* copy = new Node(curr -> val);
            curr -> next = copy;
            copy -> next = next;
            curr = next;
        }
        
        curr = head;
        while (curr != nullptr) {
            if (curr -> random != nullptr) 
                curr -> next -> random = curr -> random -> next;
            curr = curr -> next -> next;
        }
        
        curr = head;
        Node* dummy = new Node(0);
        Node* copy = dummy;
        Node* copyTail = dummy;
        
        while (curr != nullptr) {
            next = curr -> next -> next;
            copy = curr -> next;
            copyTail -> next = copy;
            copyTail = copy;
            
            curr -> next = next;
            curr = next;
        }
        return dummy -> next;
    }
};