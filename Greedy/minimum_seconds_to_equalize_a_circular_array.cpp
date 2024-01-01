// leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> getIndices(vector<int>& nums) {
        unordered_map<int, vector<int>> valueToIndices;
        
        for (int i = 0; i < nums.size(); ++i)
            valueToIndices[nums[i]].push_back(i);
        
        return valueToIndices;
    }
    
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> valueToIndices = getIndices(nums);
        int minSeconds = INT_MAX;
        int n = nums.size();
        
        for (auto& entry: valueToIndices) {
            vector<int> indices = entry.second;
            int startElements = indices.front();
            int endElements = n - 1 - indices.back();
            int currentMaxGap = (startElements + endElements + 1) / 2;
            
            for (int i = 1; i < indices.size(); ++i)
                currentMaxGap = max(currentMaxGap, (indices[i] - indices[i - 1]) / 2);
            
            minSeconds = min(minSeconds, currentMaxGap);
        }
        
        return minSeconds;
    }
};