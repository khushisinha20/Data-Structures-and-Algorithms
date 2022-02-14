//leetcode.com/problems/valid-number

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool visitedDigit = false;
        bool visitedE = false;
        bool visitedDot = false;
        int countPlusMinus = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                visitedDigit = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (countPlusMinus == 2) 
                    return false;
                if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')) 
                    return false;
                if (i == s.length() - 1)
                    return false;
                ++countPlusMinus;
            } else if (s[i] == '.') {
                if (visitedE || visitedDot) 
                    return false;
                if (i == s.length() - 1 && !visitedDigit)
                    return false;
                visitedDot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (visitedE || !visitedDigit || i == s.length() - 1)
                    return false;
                visitedE = true;
            } else {
                return false;
            }
        }
        return true;
    }
};