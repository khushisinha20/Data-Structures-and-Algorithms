//leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct comparator {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.first + a.second < b.first + b.second;
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> heap;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (heap.size() < k) 
                    heap.push({nums1[i], nums2[j]});
                else {
                    if (nums1[i] + nums2[j] < heap.top().first + heap.top().second) {
                        heap.push({nums1[i], nums2[j]});
                        heap.pop();
                    } else
                        break;
                }
            }
        }
        
        vector<int> temp;
        
        while (!heap.empty()) {
            temp.push_back(heap.top().first);
            temp.push_back(heap.top().second);
            res.push_back(temp);
            heap.pop();
            temp.clear();
        }
        
        return res;
    }
};