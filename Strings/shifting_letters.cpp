//leetcode.com/problems/shifting-letters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char shift(char letter, unsigned long long shift) {
        shift %= 26;
        if (letter + shift <= 'z') {
            letter += shift;
        } else {
            shift -= ('z' - letter + 1);
            letter = 'a' + shift;
        }
        return letter;
    }
    
    string shiftingLetters(string s, vector<int>& shifts) {
        string final_string = "";
        unsigned long long total_shifts = 0;
        total_shifts = accumulate(shifts.begin(), shifts.end(), total_shifts);
        for (int i = 0; i < s.length(); ++i) {
            final_string += shift(s[i], total_shifts);
            total_shifts -= shifts[i];
        }
        return final_string;
    }
};