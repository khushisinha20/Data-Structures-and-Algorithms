#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long result = nums.front();
        long prefixSum = result;
        
        for (int i = 1; i < nums.size(); ++i) {
            prefixSum += (long long)nums[i];
            long long currentMaximum = prefixSum / (i + 1);
            if (prefixSum % (i + 1) != 0)
                ++currentMaximum;
            result = max(result, currentMaximum);
        }
        
        return result;
    }
};