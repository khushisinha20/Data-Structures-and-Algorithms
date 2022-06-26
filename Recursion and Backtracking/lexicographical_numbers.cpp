//leetcode.com/problems/lexicographical-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& res, int i, int n) {
        if (i > n)
            return;
        
        res.push_back(i);
        for (int j = 0; j < 10; ++j) 
            dfs(res, 10 * i + j, n);
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i)
            dfs(res, i, n);
        return res;
    }
};