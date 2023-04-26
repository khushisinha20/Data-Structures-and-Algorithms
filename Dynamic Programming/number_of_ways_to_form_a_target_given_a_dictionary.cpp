//leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    const int MOD = 1e9 + 7;
    
    int helper(vector<string>& words, string& target, vector<vector<long long>>& frequency, int wordsIndex, int targetIndex) {
        if (targetIndex == target.length())
            return 1;
        
        if (wordsIndex == words[0].size())
            return 0;
        
        if (dp[wordsIndex][targetIndex] != -1)
            return dp[wordsIndex][targetIndex];
        
        int notTake = helper(words, target, frequency, wordsIndex + 1, targetIndex) % MOD;
        int take = (helper(words, target, frequency, wordsIndex + 1, targetIndex + 1) * frequency[target[targetIndex] - 'a'][wordsIndex]) % MOD;
        
        return dp[wordsIndex][targetIndex] = (notTake + take) % MOD;
    }
    
    vector<vector<long long>> getFrequency(vector<string>& words) {
        vector<vector<long long>> frequency(26, vector<long long> (words[0].length()));
        
        for (int col = 0; col < words[0].size(); ++col)
            for (auto& word: words)
                ++frequency[word[col] - 'a'][col];
        
        return frequency;
    }
    
    int numWays(vector<string>& words, string target) {
        vector<vector<long long>> frequency = getFrequency(words);
        memset(dp, -1, sizeof(dp));
        return helper(words, target, frequency, 0, 0);
    }
};