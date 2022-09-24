//leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

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

class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> adjacencyList;
    vector<int> nodesAtKDistance;
    
    void dfs(TreeNode* root) {
        if (root -> left) {
            auto left = root -> left;
            adjacencyList[left].push_back(root);
            adjacencyList[root].push_back(left);
            dfs(left);
        }
        
        if (root -> right) {
            auto right = root -> right;
            adjacencyList[right].push_back(root);
            adjacencyList[root].push_back(right);
            dfs(right);
        }
    }
    
    void bfs(TreeNode* source, int& k) {
        unordered_set<TreeNode*> processedNodes;
        queue<TreeNode*> nodes;
        nodes.push(source);
        processedNodes.insert(source);
        
        int distanceFromSource = 0;
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size--) {
                auto currentNode = nodes.front();
                nodes.pop();
                
                if (distanceFromSource == k)
                    nodesAtKDistance.push_back(currentNode -> val);
                
                for (auto adjacentNode: adjacencyList[currentNode]) {
                    if (processedNodes.find(adjacentNode) == processedNodes.end()) {
                        processedNodes.insert(adjacentNode);
                        nodes.push(adjacentNode);
                    }
                }
            }
            ++distanceFromSource;
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        bfs(target, k);
        return nodesAtKDistance;
    }
};