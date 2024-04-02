//leetcode.com/problems/score-of-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> scoreStack;

        for (char c: s) {
            if (c == '(') {
                scoreStack.push(score);
                score = 0;
            } else {
                score = scoreStack.top() + max(2 * score, 1);
                scoreStack.pop();
            }
        }

        return score;
    }
};
