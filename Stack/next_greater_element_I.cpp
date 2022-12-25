//leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void extractNextGreaterForSubset(unordered_map<int, int>& nextGreater, vector<int>& ans, vector<int>& nums1) {
        for (auto num: nums1)
            ans.push_back(nextGreater[num]);
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> elements;
        
        for (int i = nums2.size() - 1; i >= 0; --i) {
            if (!elements.empty() && elements.top() > nums2[i])
                nextGreater[nums2[i]] = elements.top();
            else {
                while (!elements.empty() && elements.top() <= nums2[i])
                    elements.pop();
                if (elements.empty())
                    nextGreater[nums2[i]] = -1;
                if (!elements.empty() && elements.top() > nums2[i])
                    nextGreater[nums2[i]] = elements.top();
            }
            elements.push(nums2[i]);
        }
        
        vector<int> ans;
        extractNextGreaterForSubset(nextGreater, ans, nums1);
        return ans;
    }
};