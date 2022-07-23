//leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findNextGreater(vector<int>& nums2, unordered_map<int, int>& mp) {
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            if (s.empty()) 
                mp[nums2[i]] = -1;   
            else if (!s.empty() && nums2[i] < s.top()) 
                mp[nums2[i]] = s.top();
            else if (!s.empty() && nums2[i] > s.top()) {
                while (!s.empty() && nums2[i] >= s.top())
                    s.pop();
                if (s.empty())
                    mp[nums2[i]] = -1;
                else
                    mp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater_elements;
        vector<int> res;
        findNextGreater(nums2, next_greater_elements);
        for (auto num: nums1)
            res.push_back(next_greater_elements[num]);
        return res;
    }
};