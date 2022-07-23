//leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening_brackets = 0;
        int closing_brackets = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                ++opening_brackets;
            else  {
                if (opening_brackets)
                    --opening_brackets; 
                else
                    ++closing_brackets;
            }
        }
        return opening_brackets + closing_brackets;
    }
};