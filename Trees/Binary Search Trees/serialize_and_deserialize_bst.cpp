//leetcode.com/problems/serialize-and-deserialize-bst/

#include <bits/stdc++.h>
using namespace std;

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
    TreeNode* deserializeHelper(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        
        if (val == "null")
            return nullptr;
        
        TreeNode* root = new TreeNode(stoi(val));
        root -> left = deserializeHelper(nodes);
        root -> right = deserializeHelper(nodes);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "null.";
        
        char DELIMETER = '.';
        string result = to_string(root -> val) + '.';
        result += serialize(root -> left);
        result += serialize(root -> right);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string node;
        
        while (getline(ss, node, '.')) {
            nodes.push(node);
        }
        
        return deserializeHelper(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;