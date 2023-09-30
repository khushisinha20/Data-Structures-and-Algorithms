//leetcode.com/problems/132-pattern/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int secondMax = INT_MIN;
        stack<int> candidatesForSecondMax;
        int n = nums.size();
        
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < secondMax)
                return true;
            
            while (!candidatesForSecondMax.empty() and nums[i] > candidatesForSecondMax.top()) {
                secondMax = max(secondMax, candidatesForSecondMax.top());
                candidatesForSecondMax.pop();
            }
            
            candidatesForSecondMax.push(nums[i]);
        }
        
        return false;
    }
};