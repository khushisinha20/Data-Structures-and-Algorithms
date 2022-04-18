//leetcode.com/problems/length-of-last-word/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                ++length;
            } else {
                if (length > 0)
                    return length;
            }
        }
        return length;
    }
};