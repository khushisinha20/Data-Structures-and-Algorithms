//leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lisFromFront(n, 1);
        
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    lisFromFront[i] = max(lisFromFront[i], lisFromFront[j] + 1);
        
        vector<int> lisFromBack(n, 1);
        
        for (int i = n - 2; i >= 0; --i)
            for (int j = n - 1; j > i; --j)
                if (nums[j] < nums[i])
                    lisFromBack[i] = max(lisFromBack[i], lisFromBack[j] + 1);
        
        int largestMountainLength = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            if (lisFromFront[i] == 1 or lisFromBack[i] == 1)
                continue;
            largestMountainLength = max(largestMountainLength, lisFromFront[i] + lisFromBack[i] - 1);
        }
        
        return n - largestMountainLength;
    }
};