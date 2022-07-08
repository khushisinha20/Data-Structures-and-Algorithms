//leetcode.com/problems/sort-array-by-parity/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.size() == 1)
            return nums;
        int i = -1;
        int j = nums.size();
        while (true) {
            do {
                ++i;
            } while (i < j && nums[i] % 2 == 0);
            do {
                --j;
            } while (j > i && nums[j] % 2 == 1);
            if (i >= j)
                break;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};