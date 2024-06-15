//leetcode.com/problems/single-threaded-cpu/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<tuple<int, int, int>> times(n);
        for (int i = 0; i < n; ++i)
            times[i] = {tasks[i][0], tasks[i][1], i};

        sort(times.begin(), times.end());

        long long currentTime = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int i = 0;
        vector<int> result;

        while (i < n or !minHeap.empty()) {
            while (i < n and get<0>(times[i]) <= currentTime) {
                minHeap.push({get<1>(times[i]), get<2>(times[i])});
                ++i;
            }

            if (!minHeap.empty()) {
                int processingTime = minHeap.top().first;
                int index = minHeap.top().second;
                minHeap.pop();
                result.push_back(index);
                currentTime += (long long)processingTime;
            } else
                currentTime = get<0>(times[i]);
        }

        return result;
    }
};
