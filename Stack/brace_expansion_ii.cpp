//leetcode.com/problems/brace-expansion-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<string> cartesianProduct(set<string>& set1, set<string>& set2) {
        if (set1.empty())
            return set2;

        if (set2.empty())
            return set1;

        set<string> result;
        for (auto& s1: set1)
            for (auto& s2: set2)
                result.insert(s1 + s2);

        return result;
    }

    set<string> evaluate(string& expression, int& pos) {
        stack<set<string>> exprStack;
        set<string> currentSet;
        set<string> tempSet;

        while (pos < expression.length()) {
            char ch = expression[pos];

            if (ch == '{') {
                ++pos;
                tempSet = evaluate(expression, pos);
                currentSet = cartesianProduct(currentSet, tempSet);
            } else if (ch == '}') {
                break;
            } else if (ch == ',') {
                exprStack.push(currentSet);
                currentSet.clear();
            } else {
                tempSet = {string(1, ch)};
                currentSet = cartesianProduct(currentSet, tempSet);
            }
            ++pos;
        }

        while (!exprStack.empty()) {
            currentSet.insert(exprStack.top().begin(), exprStack.top().end());
            exprStack.pop();
        }


        return currentSet;
    }

    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        set<string> resultSet = evaluate(expression, pos);
        vector<string> result(resultSet.begin(), resultSet.end());
        sort(result.begin(), result.end());
        return result;
    }
};
