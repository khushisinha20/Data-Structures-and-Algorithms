//leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        vector<int> uniques;
        
        for (auto& num: nums) {
            if (!seen.count(num))
                uniques.push_back(num);
            seen.insert(num);
        }
        
        sort(uniques.begin(), uniques.end());
        
        int ans = INT_MAX;
        for (int i = 0; i < uniques.size(); ++i) {
            int start = uniques[i];
            int end = uniques[i] + n - 1;
            
            auto justGreaterThanEnd = upper_bound(uniques.begin(), uniques.end(), end);
            int length = justGreaterThanEnd - uniques.begin();
            ans = min(ans, n - (length - i));
        }
        
        return ans;
    }
};