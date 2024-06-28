//leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int numOfZeroes = count(s.begin(), s.end(), '0');
        int n = s.length();
        int numOfOnes = 0;

        for (int i = 0; i < 32 and i < n; ++i) {
            if (s[n - i - 1] == '1') {
                long long weight = pow(2, i);
                if (weight <= k) {
                    ++numOfOnes;
                    k -= weight;
                } else
                    break;
            }
        }

        return numOfZeroes + numOfOnes;
    }
};
