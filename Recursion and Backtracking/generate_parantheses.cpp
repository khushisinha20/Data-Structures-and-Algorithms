//leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string& parantheses, int openBrackets, int closedBrackets, vector<string>& paranthesesCombinations) {
        if (openBrackets == 0 && closedBrackets == 0) {
            paranthesesCombinations.push_back(parantheses);
            return;
        }
        
        if (openBrackets > 0) {
            parantheses += '(';
            helper(parantheses, openBrackets - 1, closedBrackets, paranthesesCombinations);
            parantheses.pop_back();
        }

        if (closedBrackets > 0 && openBrackets < closedBrackets) {
            parantheses += ')';
            helper(parantheses, openBrackets, closedBrackets - 1, paranthesesCombinations);
            parantheses.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string parantheses = "";
        vector<string> paranthesesCombinations;
        helper(parantheses, n, n, paranthesesCombinations);
        return paranthesesCombinations;
    }
};