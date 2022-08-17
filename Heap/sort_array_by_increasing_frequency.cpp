//leetcode.com/problems/sort-array-by-increasing-frequency/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillFrequencies(vector<int>& nums, map<int, int>& freq) {
        for (int i = 0; i < nums.size(); ++i)
            ++freq[nums[i]];
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freq;
        fillFrequencies(nums, freq);
        priority_queue<pair<int, int>> max_heap;
        for (auto i: freq) 
            max_heap.push({-i.second, i.first});
        vector<int> res;
        while (!max_heap.empty()) {
            int frequency = -max_heap.top().first;
            int element = max_heap.top().second;
            for (int i = 0; i < frequency; ++i)
                res.push_back(element);
            max_heap.pop();
        }
        return res;
    }
};