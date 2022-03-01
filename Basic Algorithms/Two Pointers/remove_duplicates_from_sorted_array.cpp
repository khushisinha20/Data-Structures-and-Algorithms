//leetcode.com/problems/remove-duplicates-from-sorted-array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int i = 1;
        int j = 1;
        while (i < nums.size()) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                ++j;
            }
            ++i;
        }
        return j;
    }
};