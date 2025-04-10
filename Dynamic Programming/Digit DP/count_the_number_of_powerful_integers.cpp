//leetcode.com/problems/count-the-number-of-powerful-integers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dp[20][2][2][20];

    long long helper(string& num, string& suffix, int limit, int index, bool tight, bool leadingZero, int matched) {
        if (index == num.length()) {
            return matched == suffix.length();
        }

        if (dp[index][tight][leadingZero][matched] != -1)
            return dp[index][tight][leadingZero][matched];

        int maxDigit = tight ? (num[index] - '0') : limit;
        long long ans = 0;

        for (int digit = 0; digit <= maxDigit; ++digit) {
            if (digit > limit)
                continue;

            bool newTight = tight && (digit == maxDigit);
            bool newLeadingZero = leadingZero && (digit == 0);
            int newMatched = matched;

            if (!newLeadingZero) {
                int suffixStart = num.length() - suffix.length();
                if (index >= suffixStart) {
                    if (matched < suffix.length() && digit == (suffix[matched] - '0'))
                        ++newMatched;
                    else
                        newMatched = (digit == (suffix[0] - '0')) ? 1 : 0;
                } else {
                    newMatched = 0;
                }
            }

            ans += helper(num, suffix, limit, index + 1, newTight, newLeadingZero, newMatched);
        }

        return dp[index][tight][leadingZero][matched] = ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        memset(dp, -1, sizeof(dp));
        string upper = to_string(finish);
        long long high = helper(upper, s, limit, 0, true, true, 0);

        memset(dp, -1, sizeof(dp));
        string lower = to_string(start - 1);
        long long low = helper(lower, s, limit, 0, true, true, 0);

        return high - low;
    }
};

