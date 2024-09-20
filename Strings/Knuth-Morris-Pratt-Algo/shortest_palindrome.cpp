//leetcode.com/problems/shortest-palindrome/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> computeLPS(string& s) {
        int n = s.length();
        vector<int> lps(n, 0);
        int length = 0;
        int i = 1;

        while (i < n) {
            if (s[i] == s[length]) {
                ++length;
                lps[i] = length;
                ++i;
            } else {
                if (length != 0)
                    length = lps[length - 1];
                else
                    ++i;
            }
        }

        return lps;
    }

    string shortestPalindrome(string s) {
        if (s.empty() or s.length() == 1)
            return s;

        string rev = s;
        reverse(rev.begin(), rev.end());
        string newStr = s + "#" + rev;

        vector<int> lps = computeLPS(newStr);
        int len = lps.back();

        string toAdd = s.substr(len);
        reverse(toAdd.begin(), toAdd.end());
        return toAdd + s;
    }
};
