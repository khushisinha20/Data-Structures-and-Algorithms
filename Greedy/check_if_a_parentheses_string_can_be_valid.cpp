//leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        if (n & 1)
            return false;

        int leftBracket = 0;
        int rightBracket = 0;

        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(')
                    ++leftBracket;
                else
                    --leftBracket;
            } else
                ++leftBracket;
            if (leftBracket < 0)
                return false;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                if (s[i] == ')')
                    ++rightBracket;
                else
                    --rightBracket;
            } else
                ++rightBracket;
            if (rightBracket < 0)
                return false;
        }

        return true;
    }
};
