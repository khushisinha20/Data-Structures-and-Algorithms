//practice.geeksforgeeks.org/problems/vertical-sum/1

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

class Solution{
  public:
  void inorder(Node* root, int horizontal_position, map<int, int>& mp) {
    if (!root)
        return;
    inorder(root -> left, horizontal_position - 1, mp);
    mp[horizontal_position] += root -> data;
    inorder(root -> right, horizontal_position + 1, mp);
  }
  
    vector <int> verticalSum(Node *root) {
        map<int, int> mp;
        inorder(root, 0, mp);
        vector<int> res;
        for (auto i: mp)
            res.push_back(i.second);
        return res;
    }
};