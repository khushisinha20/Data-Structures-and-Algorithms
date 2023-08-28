//leetcode.com/problems/minimum-operations-to-form-subsequence-with-target-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillBitFrequency(vector<int>& bitFrequency, vector<int>& nums) {
        for (auto& num: nums) {
            int setBitPosition = log2(num);
            ++bitFrequency[setBitPosition];
        }
    }
    
    int minOperations(vector<int>& nums, int target) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0ll);
        vector<int> bitFrequency(32, 0);
        
        fillBitFrequency(bitFrequency, nums);
        
        if (target > totalSum)
            return -1;
        
        int smallestRequiredBit = 32;
        int operationsCount = 0;
        
        for (int i = 0; i < 31; ++i) {
            int currentBit = (1 << i);
            
            if ((target & currentBit) > 0) {
                if (bitFrequency[i] > 0)
                    --bitFrequency[i];
                else
                    smallestRequiredBit = min(i, smallestRequiredBit);
            }
            
            if (bitFrequency[i] > 0 and smallestRequiredBit < 32) {
                operationsCount += i - smallestRequiredBit;
                --bitFrequency[i];
                smallestRequiredBit = 32;
            }
            
            bitFrequency[i + 1] += bitFrequency[i] / 2;
        }
    
        return operationsCount;
    }
};