//leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        Node* current = root;
        while (current -> left) {
            Node* temp = current;
            while (current) {
                current -> left -> next = current -> right;
                if (current -> next)
                    current -> right -> next = current -> next -> left;
                else
                    current -> right -> next = nullptr;
                current = current -> next;
            }
            current = temp -> left;
        }
        return root;
    }
};