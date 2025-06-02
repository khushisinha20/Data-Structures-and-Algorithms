//leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long encode(int leftOver, const vector<int>& remainderCounts, int batchSize) {
        long long key = leftOver;
        for (int i = 1; i < batchSize; ++i) {
            key = key * 31 + remainderCounts[i];
        }
        return key;
    }

    int dfs(vector<int>& remainderCounts, int batchSize, int leftOver, unordered_map<long long, int>& memo) {
        long long key = encode(leftOver, remainderCounts, batchSize);
        if (memo.count(key))
            return memo[key];

        int result = 0;
        for (int i = 1; i < batchSize; ++i) {
            if (remainderCounts[i] == 0)
                continue;

            --remainderCounts[i];
            int newLeftOver = (leftOver + i) % batchSize;
            int addHappy = (leftOver == 0) ? 1 : 0;
            result = max(result, addHappy + dfs(remainderCounts, batchSize, newLeftOver, memo));
            ++remainderCounts[i];
        }

        return memo[key] = result;
    }

    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> remainderCounts(batchSize, 0);
        for (int group : groups) {
            ++remainderCounts[group % batchSize];
        }

        int happyGroups = remainderCounts[0];
        unordered_map<long long, int> memo;
        return happyGroups + dfs(remainderCounts, batchSize, 0, memo);
    }
};

