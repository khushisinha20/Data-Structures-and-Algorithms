//leetcode.com/classic/problems/count-ways-to-build-rooms-in-an-ant-colony/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    vector<long long> factorial, inverseFactorial;

    void precomputeFactorial(int n) {
        factorial.resize(n + 1, 1);
        inverseFactorial.resize(n + 1, 1);

        for (int i = 2; i <= n; ++i)
            factorial[i] = factorial[i - 1] * i % MOD;

        inverseFactorial[n] = modInverse(factorial[n]);
        for (int i = n - 1; i >= 0; --i)
            inverseFactorial[i] = inverseFactorial[i + 1] * (i + 1) % MOD;
    }

    long long modInverse(long long num) {
        long long result = 1;
        long long power = MOD - 2;

        while (power > 0) {
            if (power % 2 == 1)
                result = result * num % MOD;
            num = num * num % MOD;
            power /= 2;
        }

        return result;
    }

    pair<int, long long> dfs(int node, vector<vector<int>>& tree) {
        int size = 0;
        long long ways = 1;
        for (int child: tree[node]) {
            auto [childSize, childWays] = dfs(child, tree);
            size += childSize;
            ways = ways * childWays % MOD * inverseFactorial[childSize] % MOD;
        }
        ++size;
        ways = ways * factorial[size - 1] % MOD;
        return {size, ways};
    }

    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        precomputeFactorial(n);

        vector<vector<int>> tree(n);
        for (int i = 1; i < prevRoom.size(); ++i)
            tree[prevRoom[i]].push_back(i);

        return dfs(0, tree).second;
    }
};
