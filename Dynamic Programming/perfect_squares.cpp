//leetcode.com/problems/perfect-squares/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int n) {
        if (n == 0)
            return 0;
        
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; ++i) {
            ans = std::min(ans, 1 + helper(n - i * i));
        }
        
        return ans;
    }
    
    int numSquares(int n) {
        return helper(n);
    }
};


