//leetcode.com/problems/stone-game-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101][2];
    
    int helper(int index, int M, int person, vector<int>& piles) {
        if (index >= piles.size())
            return 0;
        
        if (dp[index][M][person] != -1)
            return dp[index][M][person];
        
        int result = person == 0 ? INT_MIN : INT_MAX;
        
        int stones = 0;
        
        for (int x = 1; x <= min(2 * M, (int)piles.size() - index); ++x) {
            stones += piles[index + x - 1];
            if (person == 0) {
                result = max(result, stones + helper(index + x, max(M, x), 1, piles));
            } else {
                result = min(result, helper(index + x, max(M, x), 0, piles));
            }
        }
        
        return dp[index][M][person] = result;
    }
    
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        
        return helper(0, 1, 0, piles);
    }
};