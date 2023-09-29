//leetcode.com/problems/find-all-good-indices/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        for (int i = 1; i < n; ++i)
            if (nums[i] <= nums[i - 1])
                left[i] = left[i - 1] + 1;
        
        for (int i = n - 2; i >= 0; --i)
            if (nums[i] <= nums[i + 1])
                right[i] = right[i + 1] + 1;
        
        vector<int> ans;
        
        for (int i = k; i < n - k; ++i)
            if (min(left[i - 1], right[i + 1]) >= k - 1)
                ans.push_back(i);
        
        return ans;
    }
};