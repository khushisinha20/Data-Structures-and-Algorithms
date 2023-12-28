//leetcode.com/problems/maximum-product-after-k-increments/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        
        for (int i = 0; i < k; ++i) {
            int top = minHeap.top();
            minHeap.pop();
            minHeap.push(top + 1);
        }
        
        long long maxProduct = 1;
        const int MOD = 1e9 + 7;
        
        while (!minHeap.empty()) {
            int top = minHeap.top();
            minHeap.pop();
            maxProduct = (maxProduct * top) % MOD;
        }
        
        return maxProduct % MOD;
    }
};