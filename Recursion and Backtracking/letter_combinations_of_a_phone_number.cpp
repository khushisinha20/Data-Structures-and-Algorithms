//leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int index, string& digits, string& currentCombination, unordered_map<char, string>& digitMap, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }
        
        for (int i = 0; i < digitMap[digits[index]].size(); ++i) {
            currentCombination.push_back(digitMap[digits[index]][i]);
            helper(index + 1, digits, currentCombination, digitMap, result);
            currentCombination.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        
        unordered_map<char, string> digitMap;
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";
        
        string currentCombination = "";
        vector<string> result;
        
        helper(0, digits, currentCombination, digitMap, result);
        return result;
    }
};
