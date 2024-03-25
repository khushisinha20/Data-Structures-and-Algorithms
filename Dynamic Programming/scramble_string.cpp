//leetcode.com/problems/scramble-string/

#include <bits/stdc++.h>
class Solution {
public:
    string getKey(string& s1, string& s2) {
        char DELIMETER = '-';
        return s1 + DELIMETER + s2;
    }

    bool helper(unordered_map<string, bool>& memo, string s1, string s2) {
        if (s1 == s2)
            return true;

        if (s1.length() != s2.length())
            return false;

        string key = getKey(s1, s2);

        if (memo.find(key) != memo.end())
            return memo[key];

        bool result = false;
        int n = s1.length();

        for (int i = 1; i < n; ++i) {
            bool swapped = helper(memo, s1.substr(0, i), s2.substr(n - i, i)) and helper(memo, s1.substr(i, n - i), s2.substr(0, n - i));
            if (swapped) {
                result = true;
                break;
            }

            bool notSwapped = helper(memo, s1.substr(0, i), s2.substr(0, i)) and helper(memo, s1.substr(i, n - i), s2.substr(i, n - i));
            if (notSwapped) {
                result = true;
                break;
            }
        }

        return memo[key] = result;
    }

    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> memo;
        return helper(memo, s1, s2);
    }
};
