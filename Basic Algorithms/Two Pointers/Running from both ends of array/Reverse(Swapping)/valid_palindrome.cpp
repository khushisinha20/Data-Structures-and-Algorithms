//leetcode.com/problems/valid-palindrome/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {
            if (!isalnum(s[start]))
                ++start;
            else if (!isalnum(s[end]))
                --end;
            else {
                if (tolower(s[start++]) != tolower(s[end--])) 
                    return false;
            }
        }
        return true;
    }
};

