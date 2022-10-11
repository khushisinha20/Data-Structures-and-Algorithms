//leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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
    void connectNodes(vector<Node*>& nodes) {
        for (int i = 0; i < nodes.size(); ++i) {
            if (i == nodes.size() - 1)
                nodes[i] -> next = nullptr;
            else
                nodes[i] -> next = nodes[i + 1];
        }
    }
    
    void bfs(Node* root) {
        queue<Node*> nodes;
        nodes.push(root);
        
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<Node*> currentLevelNodes;
            for (int i = 0; i < size; ++i) {
                Node* currentNode = nodes.front();
                nodes.pop();
                currentLevelNodes.push_back(currentNode);
                if (currentNode -> left)
                    nodes.push(currentNode -> left);
                if (currentNode -> right)
                    nodes.push(currentNode -> right);
            }
            connectNodes(currentLevelNodes);
        }
    }
    
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        bfs(root);
        return root;
    }
};