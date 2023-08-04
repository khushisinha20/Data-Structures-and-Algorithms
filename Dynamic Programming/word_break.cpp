//leetcode.com/problems/word-break/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(string& s, int index, unordered_set<string>& words, vector<int>& dp) {
        if (index >= s.length())
            return true;
        
        if (dp[index] != -1)
            return dp[index];
        
        for (int length = 1; length <= s.length(); ++length) {
            string extractedWord = s.substr(index, length);
            if (words.count(extractedWord) and helper(s, index + length, words, dp))
                return dp[index] = true;
        }
        
        return dp[index] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return helper(s, 0, words, dp);
    }
};