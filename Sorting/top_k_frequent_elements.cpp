//leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<pair<int, int>>& freq, int left, int right) {
        int pivot = freq[right].first;
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (freq[j].first < pivot) {
                ++i;
                swap(freq[i], freq[j]);
            }
        }
        swap(freq[i + 1], freq[right]);
        return i + 1;
    }
    
    int kthFrequency(vector<pair<int, int>>& freq, int left, int right, int k) {
        int pivot = 0;
        while (left <= right) {
            pivot = partition(freq, left, right);
            if (pivot == k)
                return freq[pivot].first;
            else if (k < pivot)
                right = pivot - 1;
            else
                left = pivot + 1;
        }
        return -1;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num: nums)
            ++mp[num];
        vector<pair<int, int>> freq;
        for (auto i: mp) 
            freq.push_back(make_pair(i.second, i.first));
        k = freq.size() - k;
        int kth_frequency = kthFrequency(freq, 0, freq.size() - 1, k);
        vector<int> res;
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i].first >= kth_frequency)
                res.push_back(freq[i].second);
        }
        return res;
    }
};