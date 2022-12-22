//leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<char> brackets;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == ']' && !brackets.empty())
                brackets.pop();
        else
            brackets.push(s[i]);
        
        return brackets.size() / 2;
    }
};