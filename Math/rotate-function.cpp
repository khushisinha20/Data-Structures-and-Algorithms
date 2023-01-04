//leetcode.com/problems/rotate-function/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void calculateInitialF(int& F, vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            F += (i * nums[i]);
    }
    
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int F = 0;
        calculateInitialF(F, nums);
        
        int maxF = F;
        int last = nums.size() - 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            F = F + (sum - (nums.size() * nums[last]));
            maxF = max(maxF, F);
            last = (last - 1 + nums.size()) % nums.size();
        }
        return maxF;
    }
};