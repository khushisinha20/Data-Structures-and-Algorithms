//leetcode.com/problems/find-the-most-competitive-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int elementsToRemove = nums.size() - k;
        
        for (int num: nums) {
            while (!st.empty() and elementsToRemove > 0 and st.top() > num) {
                st.pop();
                --elementsToRemove;
            }
            st.push(num);
        }
        
        while (st.size() > k)
            st.pop();
        
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};