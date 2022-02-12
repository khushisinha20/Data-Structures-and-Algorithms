//leetcode.com/problems/fraction-to-recurring-decimal

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        bool sign = ((numerator < 0 && denominator >= 0) || (numerator >= 0 && denominator < 0));
        long long num = abs(numerator);
        long long den = abs(denominator);
        long long quotient = num / den;
        long long remainder = num % den;
        string ans = "";
        ans = to_string(quotient);
        if (remainder == 0) {
            if (sign)
                ans = '-' + ans;
            return ans;
        } else {
            ans.push_back('.');
            unordered_map<int, int> mp;
            while (remainder != 0) {
                if (mp.find(remainder) != mp.end()) {
                    int len = mp[remainder];
                    ans = ans.substr(0, len) + '(' + ans.substr(len) + ')';
                    break;
                } else {
                    mp.insert({remainder, ans.length()});
                    remainder *= 10;
                    quotient = remainder / den;
                    remainder = remainder % den;
                    ans.push_back(quotient + '0');
                }
            }
        }
        if (sign)
            ans.insert(ans.begin(), '-');
        return ans;
    }
};