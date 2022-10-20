//leetcode.com/problems/kth-largest-element-in-a-stream/

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int limit;
    
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for (auto num: nums) {
            minHeap.push(num);
            if (minHeap.size() > limit)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > limit)
            minHeap.pop();
        return minHeap.top();
    }
};
