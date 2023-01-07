//practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector <int> nearlySorted(int arr[], int num, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < k + 1; ++i)
            minHeap.push(arr[i]);
        
        vector<int> result;
        
        for (int i = k + 1; i < num; ++i) {
            result.push_back(minHeap.top());
            minHeap.push(arr[i]);
            minHeap.pop();
        }
        
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        return result;
    }
};