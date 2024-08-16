//leetcode.com/problems/find-the-sum-of-the-power-of-all-subsequences/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int power(int n) {
        long result = 1;
        long base = 2;
        
        while (n > 0) {
            if (n % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            n >>= 1;
        }
        
        return result;
    }

    
    int helper(vector<int>& nums, vector<vector<int>>& dp, int index, int target) {
        if(target == 0)
            return power(nums.size() - index);
        
        if (index >= nums.size() || target < 0)
            return 0;
        
        if (dp[index][target] != -1)
            return dp[index][target];
        
        int waysWithoutCurrent = 2 * helper(nums, dp, index + 1, target) % MOD;
        int waysWithCurrent = helper(nums, dp, index + 1, target - nums[index]) % MOD;
        
        return dp[index][target] = (waysWithoutCurrent + waysWithCurrent) % MOD;
    }
    
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return helper(nums, dp, 0, k);
    }
};
*/

class Solution {
public:
    const int MOD = 1e9 + 7;

    int power(int n) {
        long result = 1;
        long base = 2;

        while (n > 0) {
            if (n % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            n >>= 1;
        }

        return result;
    }

    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; ++i)
            dp[i][0] = power(n - i);

        for (int i = n - 1; i >= 0; --i) {
            for (int target = 1; target <= k; ++target) {
                int waysWithoutCurrent = (2 * dp[i + 1][target]) % MOD;
                int waysWithCurrent = (target >= nums[i] ? dp[i + 1][target - nums[i]] : 0) % MOD;
                dp[i][target] = (waysWithoutCurrent + waysWithCurrent) % MOD;
            }
        }

        return dp[0][k];
    }
};
