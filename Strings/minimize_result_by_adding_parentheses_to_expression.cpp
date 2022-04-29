//leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minimizeResult(string expression) {
        int plus = expression.find('+');
        int min_value = INT_MAX;
        string minimized_result = "";
        for (int i = 0; i < plus; ++i) {
            for (int j = plus + 1; j < expression.size(); ++j) {
                string exp1 = expression.substr(0, i);
                string exp2 = expression.substr(i, plus - i);
                string exp3 = expression.substr(plus + 1, j - plus);
                string exp4 = expression.substr(j + 1);
                
                int n1 = exp1 == "" ? 1 : stoi(exp1);
                int n2 = exp2 == "" ? 1 : stoi(exp2);
                int n3 = exp3 == "" ? 1 : stoi(exp3);
                int n4 = exp4 == "" ? 1 : stoi(exp4);
                
                int num = n1 * (n2 + n3) * n4;
                if (num < min_value) {
                    min_value = num;
                    minimized_result = exp1 + '(' + exp2 + '+' + exp3 + ')' + exp4; 
                }
            }
        }
        return minimized_result;
    }
};