//leetcode.com/problems/4sum-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sums;
        
        for (auto& num1: nums1)
            for (auto& num2: nums2)
                ++sums[num1 + num2];
        
        int tuples = 0;
        
        for (auto& num3: nums3) 
            for (auto& num4: nums4) 
                if (sums[-(num3 + num4)] > 0)
                    tuples += sums[-(num3 + num4)];
        
        return tuples;
    }
};