//leetcode.com/problems/find-k-closest-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> max_heap;
        for (int i = 0; i < arr.size(); ++i) {
            max_heap.push({abs(x - arr[i]), arr[i]});
            if (max_heap.size() > k)
                max_heap.pop();
        }
        
        vector<int> res;
        while (!max_heap.empty()) {
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};