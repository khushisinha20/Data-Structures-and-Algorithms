//leetcode.com/problems/expression-add-operators/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(string& num, int target, long long value, long long previous, string expression, int start, vector<string>& result) {
        if (start >= num.length()) {
            if (value == target)
                result.push_back(expression);
            return;
        }

        for (int end = start + 1; end <= num.length(); ++end) {
            string currentStr = num.substr(start, end - start);
            if (currentStr.length() > 1 && currentStr[0] == '0')
                continue;

            long long currentValue = stoll(currentStr);
            if (start == 0)
                backtrack(num, target, currentValue, currentValue, currentStr, end, result);
            else {
                backtrack(num, target, value + currentValue, currentValue, expression + '+' + currentStr, end, result);
                backtrack(num, target, value - currentValue, -currentValue, expression + '-' + currentStr, end, result);
                backtrack(num, target, value - previous + previous * currentValue, previous * currentValue, expression + '*' + currentStr, end, result);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, 0, "", 0, result);
        return result;
    }
};

