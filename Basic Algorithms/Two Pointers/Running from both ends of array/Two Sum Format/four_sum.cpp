//leetcode.com/problems/4sum

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && (nums[i] == nums[i - 1])) 
                continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && (nums[j] == nums[j - 1])) 
                    continue;
                int sum = target - (nums[i] + nums[j]);
                int low = j + 1;
                int high = nums.size() - 1;
                while (low < high) {
                    if (nums[low] + nums[high] == sum) {
                        vector<int> ans = {nums[i], nums[j], nums[low], nums[high]};
                        res.push_back(ans);
                        while (low < high && nums[low] == nums[low + 1])
                            ++low;
                        while (low < high && nums[high] == nums[high - 1])
                            --high;
                        ++low;
                        --high;
                    } else if (nums[low] + nums[high] < sum) 
                        ++low;
                    else
                        --high;
                }
            }
        }
        return res;
    }
};