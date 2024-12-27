//leetcode.com/classic/problems/minimum-money-required-before-transactions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long maxLoss = 0;
        long long maxCashback = 0;

        for (auto& t : transactions) {
            int cost = t[0], cashback = t[1];
            if (cashback < cost) {
                maxLoss += cost - cashback;
            }
            maxCashback = max(maxCashback, static_cast<long long>(min(cost, cashback)));
        }

        return maxLoss + maxCashback;
    }
};

