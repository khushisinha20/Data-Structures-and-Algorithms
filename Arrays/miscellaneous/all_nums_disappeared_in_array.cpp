//leetcode.com/problems/find-all-numbers-disappeared-in-an-array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -(nums[abs(nums[i]) - 1]);
        }
        vector<int> missing_numbers;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                missing_numbers.push_back(i + 1);
        }
        return missing_numbers;
    }
};