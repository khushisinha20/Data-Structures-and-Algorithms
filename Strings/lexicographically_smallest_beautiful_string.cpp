//leetcode.com/problems/lexicographically-smallest-beautiful-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char next(char c) {
        return (char) (c + 1);
    }

    bool isValid(string& s, int i) {
        return (i == 0 || s[i - 1] != s[i]) && (i < 2 || s[i - 2] != s[i]);
    }

    string smallestBeautifulString(string s, int k) {
        int i = s.length() - 1;

        while (i >= 0 and i < s.length()) {
            s[i] = next(s[i]);
            while (s[i] < 'a' + k and !isValid(s, i)) {
                s[i] = next(s[i]);
            }
            if (s[i] >= 'a' + k)
                s[i--] = 'a' - 1;
            else
                ++i;
        }

        return i < 0 ? "" : s;
    }
};
