//practice.geeksforgeeks.org/problems/count-the-reversals0401/1

#include <bits/stdc++.h>
using namespace std;


int countRev (string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '{')
            st.push('{');
        else {
            if (st.empty())
                st.push('}');
            else {
                if (st.top() == '{')
                    st.pop();
                else
                    st.push('}');
            }
        }
    }
    if (st.size() % 2 == 1)
        return -1;
        
    int reversals = 0;

    int invalid_brackets = st.size();

    for (int i = 0; i < invalid_brackets; ++i) {
        if (i % 2 == 0 && st.top() == '{') 
            ++reversals;
        else if (i % 2 == 1 && st.top() == '}')
            ++reversals;
        st.pop();
    }
    return reversals;
}