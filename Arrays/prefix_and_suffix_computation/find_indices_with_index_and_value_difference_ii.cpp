//leetcode.com/problems/find-indices-with-index-and-value-difference-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSuffixMin(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMinIndices(n);
        suffixMinIndices[n - 1] = n - 1; 

        for (int i = n - 2; i >= 0; --i) {
            suffixMinIndices[i] = (nums[i] <= nums[suffixMinIndices[i + 1]]) ? i : suffixMinIndices[i + 1];
        }

        return suffixMinIndices;
    }
    
    vector<int> getSuffixMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMaxIndices(n);
        suffixMaxIndices[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; --i) {
            suffixMaxIndices[i] = (nums[i] >= nums[suffixMaxIndices[i + 1]]) ? i : suffixMaxIndices[i + 1];
        }

        return suffixMaxIndices;
    }
    
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> suffixMin = getSuffixMin(nums);
        vector<int> suffixMax = getSuffixMax(nums);
        
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + indexDifference;
            if (j < nums.size()) {
                int diffWithMin = abs(nums[i] - nums[suffixMin[j]]);
                int diffWithMax = abs(nums[i] - nums[suffixMax[j]]);
                
                if (diffWithMin >= valueDifference)
                    return {i, suffixMin[j]};
                
                if (diffWithMax >= valueDifference)
                    return {i, suffixMax[j]};
            }
        }
        
        return {-1, -1};
    }
};