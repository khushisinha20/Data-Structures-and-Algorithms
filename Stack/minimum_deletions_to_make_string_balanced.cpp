//leetcode.com/problems/minimum-deletions-to-make-string-balanced/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> stack;
        int deletions = 0;

        for (char& c: s) {
            if (c == 'b')
                stack.push(c);
            else {
                if (!stack.empty() and stack.top() == 'b') {
                    stack.pop();
                    ++deletions;
                } else
                    stack.push(c);
            }
        }

        return deletions;
    }
};

