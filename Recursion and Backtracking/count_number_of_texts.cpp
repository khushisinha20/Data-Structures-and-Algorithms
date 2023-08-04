//leetcode.com/problems/count-number-of-texts/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;

    int countCombinations(int index, const string& pressedKeys, const vector<int>& keyCount, vector<int>& dp) {
        if (index == pressedKeys.length()) 
            return 1;
        
        if (dp[index] != -1)
            return dp[index];
        
        int count = 0;
        int num = pressedKeys[index] - '0';
        int repetition = keyCount[num];

        int i = 0;
        while (i < repetition && index + i < pressedKeys.length() && pressedKeys[index] == pressedKeys[index + i]) {
            count += countCombinations(index + 1 + i, pressedKeys, keyCount, dp);
            count %= MOD;
            i++;
        }
        return dp[index] = count;
    }

    int countTexts(const string& pressedKeys) {
        vector<int> keyCount = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
        int n = pressedKeys.length();
        vector<int> dp(n, -1);
        return countCombinations(0, pressedKeys, keyCount, dp);
    }
};