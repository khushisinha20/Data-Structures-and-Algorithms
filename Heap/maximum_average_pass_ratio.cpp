//leetcode.com/problems/maximum-average-pass-ratio/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double delta(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        for (auto& cls: classes) {
            int pass = cls[0];
            int total = cls[1];
            maxHeap.push({delta(pass, total), {pass, total}});
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto [improvement, cls] = maxHeap.top();
            maxHeap.pop();
            int pass = cls.first;
            int total = cls.second;
            pass += 1;
            total += 1;
            maxHeap.push({delta(pass, total), {pass, total}});
        }

        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [improvement, cls] = maxHeap.top();
            maxHeap.pop();
            int pass = cls.first;
            int total = cls.second;
            totalRatio += (double)pass / total;
        }

        return totalRatio / classes.size();
    }
};
