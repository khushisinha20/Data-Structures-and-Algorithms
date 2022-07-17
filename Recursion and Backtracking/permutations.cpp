//leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    
    void generatePermutation(vector<int>& nums, int index, int n) {
        if (index == n) {
            result.push_back(nums);
            return;
        }
        
        for (int j = index; j <= n; ++j) {
            swap(nums[index], nums[j]);
            generatePermutation(nums, index + 1, n);
            swap(nums[index], nums[j]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        generatePermutation(nums, 0, nums.size() - 1);
        return result;
    }
};