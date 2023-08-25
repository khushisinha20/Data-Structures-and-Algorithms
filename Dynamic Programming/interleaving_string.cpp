//leetcode.com/problems/interleaving-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> dp;
    
    int isInterleaveHelper(string& s1, string& s2, string& s3, int i, int j) {
        if (i == s1.length() and j == s2.length())
            return true;
        
        string key = to_string(i) + '-' + to_string(j);
        
        if (dp.count(key))
            return dp[key];
        
        bool result = false;
        
        if (i < s1.length() and s1[i] == s3[i + j])
            result = isInterleaveHelper(s1, s2, s3, i + 1, j);
        
        if (!result and j < s2.length() and s2[j] == s3[i + j])
            result = isInterleaveHelper(s1, s2, s3, i, j + 1);
        
        return dp[key] = result;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        
        dp.clear();
        return isInterleaveHelper(s1, s2, s3, 0, 0);
    }
};