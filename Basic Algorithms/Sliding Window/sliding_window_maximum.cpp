//leetcode.com/problems/sliding-window-maximum

#include <bits/stdc++.h>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start = 0;
        deque<int> dq;
        vector<int> maximum_in_window;
        for (int end = 0; end < nums.size(); ++end) {
            while (dq.size() > 0 && dq.back() < nums[end])
                dq.pop_back();
            dq.push_back(nums[end]);
            if (end - start + 1 == k) {
                maximum_in_window.push_back(dq.front());
                if (dq.front() == nums[start])
                    dq.pop_front();
                ++start;
            }
        }
        return maximum_in_window;
    }
};