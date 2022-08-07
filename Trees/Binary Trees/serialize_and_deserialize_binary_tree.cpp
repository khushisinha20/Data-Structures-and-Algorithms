#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/serialize-and-deserialize-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    char DELIMETER = ',';
    char NULL_VAL = '*';
    
    void dfs(TreeNode* root, string& s) {
        if (!root) {
            s.push_back(NULL_VAL);
            return;
        }
        s.append(to_string(root -> val) + DELIMETER);
        dfs(root -> left, s);
        dfs(root -> right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        dfs(root, s);
        return s;
    }

    TreeNode* decode(string& data) {
        if (data.size() == 0)
            return nullptr;
        if (data[0] == '*') {
            data = data.substr(1);
            return nullptr;
        }
        string node_value = "";
        int pos = 0;
        while (data[pos] != DELIMETER) 
            node_value.push_back(data[pos++]);
        TreeNode* curr = new TreeNode(stoi(node_value));
        data = data.substr(pos + 1);
        curr -> left = decode(data);
        curr -> right = decode(data);
        return curr;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return decode(data);
    }
};