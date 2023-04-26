//leetcode.com/problems/sliding-subarray-beauty/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> frequency(101, 0);
        int start = 0;
        vector<int> result;
        
        for (int end = 0; end < nums.size(); ++end) {
            ++frequency[nums[end] + 50];
            if (end - start + 1 == k) {
                int currentPosition = 0;
                for (int i = 0; i < frequency.size(); ++i) {
                    if (x - currentPosition <= frequency[i]) {
                        currentPosition += (x - currentPosition);
                        if (i - 50 < 0)
                            result.push_back(i - 50);
                        else
                            result.push_back(0);
                        break;
                    } else
                        currentPosition += frequency[i];
                }
                --frequency[nums[start] + 50];
                ++start;
            }
        }
        
        return result;
    }
};