//practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

vector<int> leftView(Node *root) {
   vector<int> res;
   queue<Node*> q;
   q.push(root);
   if (!root)
    return res;
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* node = q.front();
            q.pop();
            if (i == 0)
                res.push_back(node -> data);
            if (node -> left)
                q.push(node -> left);
            if (node -> right)
                q.push(node -> right);
        }
    }
    return res;
}
