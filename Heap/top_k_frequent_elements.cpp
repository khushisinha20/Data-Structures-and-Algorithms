//leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillFrequencies(vector<int>& nums, map<int, int>& freq) {
        for (int i = 0; i < nums.size(); ++i)
            ++freq[nums[i]];
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        fillFrequencies(nums, freq);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto i: freq) {
            min_heap.push({i.second, i.first});
            if (min_heap.size() > k)
                min_heap.pop();
        }
        vector<int> res;
        while (!min_heap.empty()) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};