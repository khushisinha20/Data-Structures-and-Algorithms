//leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct comparator {
        bool operator() (string& a, string& b) {
            if (a.length() == b.length())
                return a > b;
            return a.length() > b.length();
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, comparator> min_heap;
        for (int i = 0; i < nums.size(); ++i) {
            min_heap.push(nums[i]);
            if (min_heap.size() > k)
                min_heap.pop();
        }
        return min_heap.top();
    }
};