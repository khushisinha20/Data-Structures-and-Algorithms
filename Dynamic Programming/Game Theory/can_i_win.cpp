class Solution {
public:
    unordered_map<int, bool> dp;
    
    bool helper(int& maxChoosableInteger, int& desiredTotal, int mask, int currentSum) {
        if (currentSum >= desiredTotal)
            return false;
        
        if (dp.find(mask) != dp.end())
            return dp[mask];
        
        for (int i = 1; i <= maxChoosableInteger; ++i) {
            int num = 1 << i;
            if (!(mask & num)) {
                if (!helper(maxChoosableInteger, desiredTotal, mask | num, currentSum + i)) 
                    return dp[mask] = true;
            }
        }
        
        return dp[mask] = false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (sum < desiredTotal)
            return false;
        
        if (desiredTotal == 0)
            return true;
        
        dp.clear();
        return helper(maxChoosableInteger, desiredTotal, 0, 0);
    }
};
