//leetcode.com/problems/longest-happy-prefix/

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

    string longestPrefix(string s) {
        vector<int> lps = computeLPS(s);
        int length = lps.back();
        return s.substr(0, length);
    }
};
