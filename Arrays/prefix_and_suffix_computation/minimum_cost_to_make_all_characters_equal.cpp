//leetcode.com/problems/minimum-cost-to-make-all-characters-equal/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> getPrefixOperations(const string& s) {
        int n = s.length();
        vector<long long> prefix(n);
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1];
            if (s[i - 1] != s[i]) {
                prefix[i] += i;
            }
        }
        return prefix;
    }

    vector<long long> getSuffixOperations(const string& s) {
        int n = s.length();
        vector<long long> suffix(n);
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1];
            if (s[i] != s[i + 1]) {
                suffix[i] += (n - 1 - i);
            }
        }
        return suffix;
    }

    long long minimumCost(string s) {
        vector<long long> prefix = getPrefixOperations(s);
        vector<long long> suffix = getSuffixOperations(s);
        long long minCost = LLONG_MAX;

        for (int i = 0; i < s.length(); ++i) {
            minCost = min(minCost, prefix[i] + suffix[i]);
        }

        return minCost;
    }
};

