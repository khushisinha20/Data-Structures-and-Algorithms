//leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void markInvalidClosingBrackets(stack<int>& bracketIndices, string& s) {
        for (int i = 0; i < s.length(); ++i) {
            if (bracketIndices.empty()) {
                if (s[i] == '(') 
                    bracketIndices.push(i);
                if (s[i] == ')')
                    s[i] = '.';
            } else {
                if (s[i] == '(')
                    bracketIndices.push(i);
                if (s[i] == ')') {
                    if (!bracketIndices.empty())
                        bracketIndices.pop();
                    else
                        s[i] = '.';
                }
            }
        }
    }
    
    void markInvalidOpeningBrackets(stack<int>& bracketIndices, string& s) {
        while (!bracketIndices.empty()) {
            s[bracketIndices.top()] = '.';
            bracketIndices.pop();
        }
    }
    
    string validString(string& s) {
        string validParentheses;
        for (auto character: s)
            if (character != '.')
                validParentheses.push_back(character);
        return validParentheses;
    }
    
    string minRemoveToMakeValid(string s) {
        stack<int> bracketIndices;
        markInvalidClosingBrackets(bracketIndices, s);
        markInvalidOpeningBrackets(bracketIndices, s);
        return validString(s);
    }
};