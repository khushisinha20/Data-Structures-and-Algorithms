//leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> maxLengthTillNow;
        int ans = 0;
        for (int i = arr.size() - 1; i >= 0; --i) {
            maxLengthTillNow[arr[i]] = maxLengthTillNow[arr[i] + difference] + 1;
           ans = max(ans, maxLengthTillNow[arr[i]]); 
        }
        
        return ans;
    }
};