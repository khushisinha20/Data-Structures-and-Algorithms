//practice.geeksforgeeks.org/problems/k-distance-from-root/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void kDistanceFromRoot(Node* root, int k, vector<int>& nodes) {
    if (!root || k < 0)
        return;
    if (k == 0) {
        nodes.push_back(root -> data);
        return;
    } else {
        kDistanceFromRoot(root -> left, k - 1, nodes);
        kDistanceFromRoot(root -> right, k - 1, nodes);
    }
}

vector<int> Kdistance(struct Node *root, int k) {
  vector<int> nodes;
  kDistanceFromRoot(root, k, nodes);
  return nodes;
}