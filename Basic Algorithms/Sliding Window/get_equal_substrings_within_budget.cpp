//leetcode.com/problems/get-equal-substrings-within-budget/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int max_length = 0;
        int costNeeded = 0;
        int start = 0;
        for (int end = 0; end < s.length(); ++end) {
            costNeeded += abs(s[end] - t[end]);
            if (costNeeded <= maxCost)
                max_length = max(max_length, end - start + 1);
            while (costNeeded > maxCost) {
                costNeeded -= abs(s[start] - t[start]);
                ++start;
            }
        }
        return max_length;
    }
};