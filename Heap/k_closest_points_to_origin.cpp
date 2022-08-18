//leetcode.com/problems/k-closest-points-to-origin/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> max_heap;
        for (int i = 0; i < points.size(); ++i) {
            int abscissa = points[i][0];
            int ordinate = points[i][1];
            max_heap.push({abscissa * abscissa + ordinate * ordinate, points[i]});
            if (max_heap.size() > k)
                max_heap.pop();
        }
        vector<vector<int>> res;
        while (!max_heap.empty()) {
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return res;
    }
};