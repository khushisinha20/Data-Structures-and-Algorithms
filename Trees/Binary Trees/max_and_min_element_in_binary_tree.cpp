//practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(Node *root) {
        if (root == NULL) 
            return INT_MIN;
        return max(root -> data, max(findMax(root -> left), findMax(root -> right)));
    }
    int findMin(Node *root) {
        if (root == NULL) 
            return INT_MAX;
        return min(root -> data, min(findMin(root -> left), findMin(root -> right)));
    }
};