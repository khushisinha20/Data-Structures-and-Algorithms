//leetcode.com/problems/permutations-ii/

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
        
        unordered_set<int> visited;
        
        for (int j = index; j <= n; ++j) {
            if (visited.find(nums[j]) == visited.end()) {
                swap(nums[index], nums[j]);
                generatePermutation(nums, index + 1, n);
                swap(nums[index], nums[j]);
                visited.insert(nums[j]);
            }
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        generatePermutation(nums, 0, nums.size() - 1);
        return result;
    }
};