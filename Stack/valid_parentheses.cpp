//leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOpeningBracket(char& a) {
        return (a == '(') || (a == '{') || (a == '[');
    }
    
    bool isBalanced(char& b, char& a) {
        return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
    }
    
    bool isValid(string s) {
        stack<int> brackets;
        for (int i = 0; i < s.length(); ++i) {
            if (isOpeningBracket(s[i]))
                brackets.push(s[i]);
            else {
                if (brackets.empty())
                    return false;
                char bracket = brackets.top();
                brackets.pop();
                if (!isBalanced(s[i], bracket))
                    return false;
            }
        }
        return brackets.empty();
    }
};