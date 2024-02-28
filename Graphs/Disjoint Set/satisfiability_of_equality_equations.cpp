//leetcode.com/problems/satisfiability-of-equality-equations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    
    void Union(int x, int y) {
        int parentX = parent[x];
        int parentY = parent[y];
        
        if (parentX != parentY) {
            if (rank[parentX] > rank[parentY]) {
                parent[parentY] = parentX;
            } else if (rank[parentY] > rank[parentY]) {
                parent[parentX] = parentY;
            } else {
                parent[parentX] = parentY;
                ++rank[parentY];
            }
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 1);
        
        for (int i = 0; i < 26; ++i)
            parent[i] = i;
        
        for (auto& equation: equations)
            if (equation[1] == '=')
                Union(equation[0] - 'a', equation[3] - 'a');
        
        for (auto& equation: equations) {
            if (equation[1] == '!') {
                if (find(equation[0] - 'a') == find(equation[3] - 'a'))
                    return false;
            }
        }
        
        return true;
    }
};