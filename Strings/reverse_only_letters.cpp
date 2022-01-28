//leetcode.com/problems/reverse-only-letters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isLetter(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }
    
    string reverseOnlyLetters(string s) {
        int j = s.length() - 1;
        int i = 0;
        while (i <= j) {
            if (isLetter(s[i]) && (isLetter(s[j]))) {
                swap(s[i], s[j]);
                ++i;
                --j;
            } else if (isLetter(s[i]) && (!isLetter(s[j]))) {
                --j;
            } else if ((!isLetter(s[i])) && (isLetter(s[j]))) {
                ++i;
            } else {
                ++i;
                --j;
            }
        }
        return s;
    }
};