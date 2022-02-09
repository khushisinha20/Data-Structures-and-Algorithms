//leetcode.com/problems/count-and-say/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";
        string s = "11";
        char DELIMETER = '.';
        for (int i = 3; i <= n; ++i) {
            int continuous_characters_count = 1; 
            s += DELIMETER;
            string temp = "";
            for (int j = 1; j < s.length(); ++j) {
                if (s[j - 1] != s[j]) {
                    temp += to_string(continuous_characters_count);
                    temp += s[j - 1];
                    continuous_characters_count = 1;
                } else {
                    ++continuous_characters_count;
                }
            }
            s = temp;
        }
        return s;
    }
};