//leetcode.com/problems/subarrays-with-k-different-integers/submissions/

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysWithAtmostKDistinct(vector<int>& nums, int k) {
        int required_subarrays = 0;
        int start = 0;
        unordered_map<int, int> mp;
        for (int end = 0; end < nums.size(); ++end) {
            ++mp[nums[end]];
            while (mp.size() > k) {
                --mp[nums[start]];
                if (mp[nums[start]] == 0)
                    mp.erase(nums[start]);
                ++start;
            }
            if (mp.size() <= k)
                required_subarrays += (end - start + 1);
        }
        return required_subarrays;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums, k - 1);
    }
};