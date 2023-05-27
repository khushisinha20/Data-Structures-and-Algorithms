//leetcode.com/problems/stone-game-iii/

#include <bits/stdc+.h>
using namespace std;

class Solution {
public:
   string stoneGameIII(vector<int>& stoneValue) {
       vector<int> dp;
       dp.resize(stoneValue.size() + 1);

       int n = stoneValue.size();

       for (int i = n - 1; i >= 0; --i) {
           dp[i] = stoneValue[i] - dp[i + 1];

           if (i + 1 < n)
               dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);

           if (i + 2 < n)
               dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
       }

       int differenceInScores = dp[0];

       if (differenceInScores < 0)
            return "Bob";
       else if (differenceInScores > 0)
            return "Alice";
       else
            return "Tie";

        return "";
    }
};
