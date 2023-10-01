//leetcode.com/problems/remove-invalid-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;
    unordered_set<string> visited;
    
    int getMinInvalidCount(string& s) {
        stack<char> parenthesesStack;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                parenthesesStack.push('(');
            } else if (s[i] == ')') {
                if (!parenthesesStack.empty() and parenthesesStack.top() == '(') 
                    parenthesesStack.pop();
                else
                    parenthesesStack.push(')');
            }
        }
        
        return parenthesesStack.size();
    }
    
    void backtrack(string currentExpression, int invalidCount) {
        if (visited.find(currentExpression) != visited.end())
            return;
        
        visited.insert(currentExpression);
        
        if (invalidCount < 0)
            return;
        
        if (invalidCount == 0) {
            if (!getMinInvalidCount(currentExpression))
                result.push_back(currentExpression);
            return;
        }
        
        for (int i = 0; i < currentExpression.length(); ++i) {
            string left = currentExpression.substr(0, i);
            string right = currentExpression.substr(i + 1);
            backtrack(left + right, invalidCount - 1);
        }
        
        return;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int minInvalidCount = getMinInvalidCount(s);
        backtrack(s, minInvalidCount);
        return result;
    }
};