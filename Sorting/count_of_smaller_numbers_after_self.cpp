//leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void countAndMerge(vector<pair<int, int>>& v, vector<int>& count, int low, int mid, int high) {
        vector<pair<int, int>> left(v.begin() + low, v.begin() + mid + 1);
        vector<pair<int, int>> right(v.begin() + mid + 1, v.begin() + high + 1);
        int i = 0;
        int j = 0;
        int curr_idx = low;
        while (i < left.size() && j < right.size()) {
            if (left[i].first <= right[j].first) {
                v[curr_idx++] = right[j++];
            } else {
                count[left[i].second] += (right.size() - j);
                v[curr_idx++] = left[i++];
            }
        }
        while (i < left.size())
            v[curr_idx++] = left[i++];
        while (j < right.size())
            v[curr_idx++] = right[j++];
    }
    
    void countAndMergeSort(vector<pair<int, int>>& v, vector<int>& count, int low, int high) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        countAndMergeSort(v, count, low, mid);
        countAndMergeSort(v, count, mid + 1, high);
        countAndMerge(v, count, low, mid, high);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); ++i) 
            v.push_back(make_pair(nums[i], i));
        countAndMergeSort(v, count, 0, n - 1);
        return count;
    }
};