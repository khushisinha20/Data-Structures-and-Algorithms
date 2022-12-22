//leetcode.com/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    bool isOperand(string& token) {
        return token != "+" && token != "-" && token != "*" && token != "/";
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        
        for (int i = 0; i < tokens.size(); ++i) {
            if (isOperand(tokens[i])) {
                operands.push(stoi(tokens[i]));
            } else {
                int firstOperand = operands.top();
                operands.pop();
                int secondOperand = operands.top();
                operands.pop();
                
                if (tokens[i] == "+")
                    operands.push(secondOperand + firstOperand);
                if (tokens[i] == "-")
                    operands.push(secondOperand - firstOperand);
                if (tokens[i] == "*")
                    operands.push(secondOperand * firstOperand);
                if (tokens[i] == "/")
                    operands.push(secondOperand / firstOperand);
            }
        }
        return operands.top();
    }
};