//leetcode.com/problems/closest-equal-element-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> valToIndex;
        int n = nums.size();

        for (int i = 0; i < nums.size(); ++i)
            valToIndex[nums[i]].push_back(i);

        vector<int> minDist(n, -1);

        for (auto& [val, arr]: valToIndex) {
            int size = arr.size();
            if (size == 1)
                continue;
            for (int i = 0; i < size; ++i) {
                int current = arr[i];
                int next = arr[(i + 1) % size];
                int previous = arr[(i - 1 + size) % size];
                int forward = (next - current + n) % n;
                int backward = (current - previous + n) % n;
                minDist[current] = min(forward, backward);
            }
        }

        vector<int> result;
        for (auto& query: queries)
            result.push_back(minDist[query]);

        return result;
    }
};
