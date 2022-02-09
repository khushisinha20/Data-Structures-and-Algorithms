//leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int to_integer(char c) {
        return c - '0';
    }
    
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    
    bool areNumbersAscending(string s) {
        int current_number = 0;
        int previous_number = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isNumber(s[i])) {
                current_number = (current_number * 10 + to_integer(s[i]));
            } else if (current_number != 0) {
                if (previous_number >= current_number) 
                    return false;
                previous_number = current_number;
                current_number = 0;
            }
        }
        return current_number == 0 || previous_number < current_number;
    }
};