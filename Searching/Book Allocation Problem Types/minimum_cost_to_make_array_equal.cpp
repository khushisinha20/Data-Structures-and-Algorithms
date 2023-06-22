#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/minimum-cost-to-make-array-equal/

class Solution {
public:
    long long findCost(vector<int>& nums, vector<int>& cost, int target) {
        long long result = 0;
        
        for (int i = 0; i < nums.size(); ++i)
            result += (long long) abs(nums[i] - target) * cost[i];
        
        return result;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long answer = 0;
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long cost1 = findCost(nums, cost, mid);
            long long cost2 = findCost(nums, cost, mid + 1);
            if (cost1 < cost2) {
                answer = cost1;
                right = mid - 1;
            } else {
                answer = cost2;
                left = mid + 1;
            }
        }
        
        return answer;
    }
};