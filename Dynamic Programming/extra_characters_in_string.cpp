//leetcode.com/problems/extra-characters-in-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(string& s, int index, unordered_set<string>& words, vector<int>& dp) {
        if (index >= s.length())
            return 0;
        
        if (dp[index] != -1)
            return dp[index];
        
        int result = INT_MAX;
        for (int length = 1; index + length <= s.length(); ++length) {  
            string extractedWord = s.substr(index, length);
            if (words.find(extractedWord) != words.end())
                result = min(result, 0 + helper(s, index + length, words, dp));
            else
                result = min(result, length + helper(s, index + length, words, dp));
        }
        
        return dp[index] = result;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> words(dictionary.begin(), dictionary.end());
        vector<int> dp(s.length(), -1);
        int ans = helper(s, 0, words, dp);
        return ans == INT_MAX ? 0 : ans;
    }
};
