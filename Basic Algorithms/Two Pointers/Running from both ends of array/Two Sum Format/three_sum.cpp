//leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 2)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int low = i + 1;
                int high = nums.size() - 1;
                int sum = 0 - nums[i];
                while (low < high) {
                    if (nums[low] + nums[high] == sum) {
                        result.push_back({nums[i], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1]) 
                            ++low;
                        while (low < high && nums[high] == nums[high - 1])
                            --high;
                        ++low;
                        --high;
                    } else if (nums[low] + nums[high] < sum) {
                        ++low;
                    } else {
                        --high;
                    }
                }
            }
        }
        return result;
    }
};