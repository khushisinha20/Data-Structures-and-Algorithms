//leetcode.com/problems/palindrome-partitioning-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        if (left >= right)
            return true;
        
        while (left < right) {
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
    
    int helper(string& s, int left, int right, vector<vector<int>>& dp) {
        if (left >= right)
            return 0;
        
        if (dp[left][right] != -1) 
            return dp[left][right];
        
        
        if (isPalindrome(s, left, right))
            return dp[left][right] = 0;
        
        int minPartitions = s.length() - 1;
        
        for (int i = left; i < right; ++i) {
            if (isPalindrome(s, left, i)) {
                int partitions = helper(s, i + 1, right, dp) + 1;
                minPartitions = min(minPartitions, partitions);
            }
        }
        
        return dp[left][right] = minPartitions;
    }
    
    int minCut(string s) {
        vector<vector<int>> dp(s.length() + 1, vector<int> (s.length() + 1, -1));
        return helper(s, 0, s.length() - 1, dp);
    }
};