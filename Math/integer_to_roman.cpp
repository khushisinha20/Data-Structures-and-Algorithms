//leetcode.com/problems/integer-to-roman/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman_numeral = "";
        for (int i = 0; num != 0; ++i) {
            while (num >= values[i]) {
                num -= values[i];
                roman_numeral += (symbols[i]);
            }
        }
        return roman_numeral;
    }
};