//practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node { 
	int data;
	struct Node* next;
	struct Node* bottom;
	
	Node(int x) {
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};

Node* merge(Node* first, Node* second) {
    if (first == NULL)
        return second;
        
    if (second == NULL)
        return first;
    
    Node* curr = new Node(0);
    Node* merged_list = curr;
    
    while (first && second) {
        if (first -> data < second -> data) {
            curr -> bottom = first;
            curr = first;
            first = first -> bottom;
        } else {
            curr -> bottom = second;
            curr = second;
            second = second -> bottom;
        }
    }
    
    while (first) {
        curr -> bottom = first;
        curr = first;
        first = first -> bottom;
    }
    
    while (second) {
        curr -> bottom = second;
        curr = second;
        second = second -> bottom;
    }
    
    return merged_list -> bottom;
}

Node* flatten(Node* root) {
    if (root == nullptr || root -> next == nullptr)
        return root;
    root -> next = flatten(root -> next);
    root = merge(root, root -> next);
    return root;
}


