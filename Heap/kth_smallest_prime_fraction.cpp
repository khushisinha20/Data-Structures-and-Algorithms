//leetcode.com/problems/k-th-smallest-prime-fraction/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct comparator {
        bool operator() (pair<int, int> const a, pair<int, int> const b) {
            return a.first * b.second < a.second * b.first; 
        }
    };
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> maxHeap;
        for (int i = 0; i < arr.size() - 1; ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                maxHeap.push({arr[i], arr[j]});
                if (maxHeap.size() > k)
                    maxHeap.pop();
            }
        }
        return {maxHeap.top().first, maxHeap.top().second};
    }
};