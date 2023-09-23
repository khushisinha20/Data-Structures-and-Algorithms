//leetcode.com/problems/append-characters-to-string-to-make-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;
        
        while (i < s.length() and j < t.length()) {
            if (s[i] == t[j]) 
                ++j;
            ++i;
        }
        
        return t.length() - j;
    }
};