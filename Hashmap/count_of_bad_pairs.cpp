//leetcode.com/problems/count-number-of-bad-pairs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long, long long> mp;
        long long n = nums.size();
        long long bad_pairs = n * (n - 1) / 2;
        for (int i = 0; i < nums.size(); ++i) {
            long long key = nums[i] - i;
            if (mp.find(key) != mp.end())
                bad_pairs -= mp[key];
            ++mp[key];
        }
        return bad_pairs;
    }
};