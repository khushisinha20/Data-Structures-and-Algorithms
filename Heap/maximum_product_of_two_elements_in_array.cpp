//leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto& num: nums) {
            min_heap.push(num);
            if (min_heap.size() > 2)
                min_heap.pop();
        }
        int a = min_heap.top();
        min_heap.pop();
        
        int b = min_heap.top();
        min_heap.pop();
        
        return (a - 1) * (b - 1);
    }
};