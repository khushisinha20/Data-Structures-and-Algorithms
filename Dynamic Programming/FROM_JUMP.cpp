//leetcode.com/problems/frog-jump/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    
    unordered_map<int, int> mapStonesWithIndex(vector<int>& stones) {
        unordered_map<int, int> stoneIndexMap;
        for (int i = 0; i < stones.size(); ++i)
            stoneIndexMap[stones[i]] = i;
        return stoneIndexMap;
    }
    
    bool helper(vector<int>& stones, int currentStoneIndex, int previousJump, unordered_map<int, int>& stoneIndexMap) {
        if (currentStoneIndex == stones.size() - 1)
            return true;
        
        if (currentStoneIndex >= stones.size())
            return false;
        
        if (dp[currentStoneIndex][previousJump] != -1)
            return dp[currentStoneIndex][previousJump];
        
        bool result = false;
        
        for (int nextJump = previousJump - 1; nextJump <= previousJump + 1; ++nextJump) {
            if (nextJump > 0) {
                int nextPosition = stones[currentStoneIndex] + nextJump;
                if (stoneIndexMap.find(nextPosition) != stoneIndexMap.end()) {
                    result |= helper(stones, stoneIndexMap[nextPosition], nextJump, stoneIndexMap);
                }
            }
        }
        
        return dp[currentStoneIndex][previousJump] = result;
    }
    
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> stoneIndexMap = mapStonesWithIndex(stones);
        
        if (stones[1] != 1)
            return false;
        
        dp.resize(2001, vector<int> (2001, -1));
        
        return helper(stones, 0, 0, stoneIndexMap);
    }
};