//leetcode.com/problems/validate-stack-sequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //using pushed array as a stack
        int top = 0;
        int currentPopped = 0;
        for (auto element: pushed) {
            pushed[top++] = element;
            while (top > 0 && pushed[top - 1] == popped[currentPopped]) {
                --top;
                ++currentPopped;
            }
        }
        return top == 0;
    }
};