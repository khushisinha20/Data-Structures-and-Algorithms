//leetcode.com/problems/solving-questions-with-brainpower/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long helper(int index, vector<vector<int>>& questions, vector<long long>& dp) {
        if (index >= questions.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        long long pick = helper(index + questions[index][1] + 1, questions, dp) + questions[index][0];
        long long notPick = helper(index + 1, questions, dp);

        return dp[index] = max(pick, notPick);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        helper(0, questions, dp);
        return helper(0, questions, dp);
    }
};
