//leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int pairs = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            ++mp[nums[i]];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target.substr(0, nums[i].size())) {
                string remaining = target.substr(nums[i].size());
                if (mp.find(remaining) != mp.end()) {
                    pairs += mp[remaining];
                    if (remaining == nums[i])
                        --pairs;
                }
            }
        }
        return pairs;
    }
};