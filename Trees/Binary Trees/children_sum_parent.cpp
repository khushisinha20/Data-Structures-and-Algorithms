//practice.geeksforgeeks.org/problems/children-sum-parent/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
    public:
    int isSumProperty(Node *root) {
        if (!root)
            return 1;
        
        if (!(root -> left) && !(root -> right))
            return 1;
        
        int sum = 0;
        
        if (root -> left)
            sum += root -> left -> data;
        if (root -> right)
            sum += root -> right -> data;
            
        return (sum == root -> data && isSumProperty(root -> left) && isSumProperty(root -> right));
    }
};