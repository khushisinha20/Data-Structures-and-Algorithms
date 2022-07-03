//leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int start = 0;
        int end = s.length() - 1;
        int ch = 0;
        
        while (start < end && s[start] == s[end]) {
            ch = s[start];
            while (start < end && s[start] == ch)
                ++start;
            while (start < end && s[end] == ch)
                --end;
        }
        if (s[start] == ch)
            return 0;
        return end - start + 1;
    }
};