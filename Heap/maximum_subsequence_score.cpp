//leetcode.com/problems/maximum-subsequence-score/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool comparator(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

public:
    void fillPairs(vector<pair<int, int>>& numPairs, vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); ++i)
            numPairs.push_back({nums1[i], nums2[i]});
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> numPairs;
        fillPairs(numPairs, nums1, nums2);
        sort(numPairs.begin(), numPairs.end(), comparator);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long result = 0;

        for (auto& numPair: numPairs) {
            minHeap.push(numPair.first);
            sum += numPair.first;
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k)
                result = max(result, sum * numPair.second);
        }

        return result;
    }
};
