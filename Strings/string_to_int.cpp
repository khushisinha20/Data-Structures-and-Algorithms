//leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long atoi(string& s, int index, int sign, long long result) {
        if (sign * result >= INT_MAX)
            return INT_MAX;
        
        if (sign * result <= INT_MIN)
            return INT_MIN;
        
        if (index >= s.length() or !isdigit(s[index]))
            return result * sign;
        
        result = atoi(s, index + 1, sign, result * 10 + (s[index] - '0'));
        return result;
    }
    
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        
        while (i < n and s[i] == ' ')
            ++i;
        
        if (s[i] == '-') {
            sign *= -1;
            ++i;
        } else if (s[i] == '+') 
            ++i;
        
        return atoi(s, i, sign, 0);
    }
};