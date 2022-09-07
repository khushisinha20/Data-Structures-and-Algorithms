//leetcode.com/problems/clone-graph/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    vector<Node*> vertices;
    
    Solution() {
        vertices = vector<Node*> (101, NULL);
    }
    
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        Node* vertex = new Node(node -> val);
        vertices[node -> val] = vertex;
        for (Node* adjacentNode: node -> neighbors) {
            if (!vertices[adjacentNode -> val]) 
                vertex -> neighbors.push_back(cloneGraph(adjacentNode));
            else
                vertex -> neighbors.push_back(vertices[adjacentNode -> val]);
        }
        return vertex;
    }
};