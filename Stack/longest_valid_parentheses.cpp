#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2)
            return 0;
        
        stack<int> st;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st.push(i);
            else {
                if (!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
            }
        }
        
        int maxLength = 0;
        int start = 0;
        int end = s.length();
        while (!st.empty()) {
            start = st.top();
            maxLength = max(maxLength, end - start - 1);
            end = start;
            st.pop();
        }
        
        maxLength = max(maxLength, end);
        
        return maxLength;
    }
};