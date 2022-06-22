//leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.size() == 0) 
            return {};
        if (digits.size() == 1) {
            string str = letters[digits[0] - '0'];
            vector<string> res(str.length());;
            for (int i = 0; i < str.length(); ++i) 
                res[i] = str[i];
            return res;
        }
        char first_digit = digits[0];
        string rest_of_string = digits.substr(1, digits.length() - 1);
        vector<string> combinations = letterCombinations(rest_of_string);
        for (auto i: letters[first_digit - '0']) {
            for (auto j: combinations) {
                res.push_back(i + j);
            }
        }
        return res;
    }
};