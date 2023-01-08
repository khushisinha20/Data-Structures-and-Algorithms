//leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //O(k log k)
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (maxHeap.size() < k)
                    maxHeap.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                else {
                    if (nums1[i] + nums2[j] >= maxHeap.top().first)
                        break;
                    else {
                        maxHeap.pop();
                        maxHeap.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                    }
                }
            }
        }
        
        vector<vector<int>> result;
        
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};