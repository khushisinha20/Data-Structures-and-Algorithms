//leetcode.com/problems/k-divisible-elements-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> distinct_subarrays;
        int multiples_of_p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            multiples_of_p = 0;
            vector<int> subarray;
            for (int j = i; j < nums.size(); ++j) {
                subarray.push_back(nums[j]);
                if (nums[j] % p == 0)
                    ++multiples_of_p;
                if (multiples_of_p > k)
                    break;
                distinct_subarrays.insert(subarray);
            }
        }
        return distinct_subarrays.size();
    }
};