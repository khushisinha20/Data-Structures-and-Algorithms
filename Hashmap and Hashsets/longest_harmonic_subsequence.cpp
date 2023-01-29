//leetcode.com/problems/longest-harmonious-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for (auto num: nums)
            ++frequency[num];
        
        int maxLength = 0;
        for (auto [num, freq]: frequency) {
            if (frequency.find(num + 1) != frequency.end()) 
                maxLength = max(maxLength, freq + frequency[num + 1]);
        }
        return maxLength;
    }
};