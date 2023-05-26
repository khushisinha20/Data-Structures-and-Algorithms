//leetcode.com/problems/find-the-punishment-number-of-an-integer/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBePartitioned(string s, int index, int targetSum) {
        if (index >= s.length())
            return targetSum == 0;

        long long sum = 0;
        bool result = false;

        for (int i = index; i < s.length(); ++i) {
            sum = sum * 10 + (s[i] - '0');
            result |= canBePartitioned(s, i + 1, targetSum - sum);
        }

        return result;
    }

    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (canBePartitioned(to_string(i * i), 0, i))
                result += (i * i);
        }

        return result;
    }
};
