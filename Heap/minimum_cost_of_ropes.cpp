//practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc+.h>
using namespace std;

class Solution {
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        for (int i = 0; i < n; ++i)
            minHeap.push(arr[i]);
            
        long long cost = 0;
        
        while (minHeap.size() >= 2) {
            long long currentCost = minHeap.top();
            minHeap.pop();
            currentCost += minHeap.top();
            minHeap.pop();
            cost += currentCost;
            minHeap.push(currentCost);
        }
        
        return cost;
    }
};