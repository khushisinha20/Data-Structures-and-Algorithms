#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
            return nullptr;
        
        Node* current = head;
        
        while (current) {
            if (current -> child) {
                Node* nextNode = current -> next; // storing the next node of the previous level
                
                Node* flattenedChild = flatten(current -> child); // flattening the child list
                current -> next = flattenedChild; 
                flattenedChild -> prev = current; // attaching previous of child to parent
                current -> child = nullptr;
                
                while (current -> next)
                    current = current -> next; 
                
                if (nextNode) {
                    current -> next = nextNode; // attaching the end to child to next of previous 
                    nextNode -> prev = current;
                }
            }
            current = current -> next;
        }
        
        return head;
    }
};