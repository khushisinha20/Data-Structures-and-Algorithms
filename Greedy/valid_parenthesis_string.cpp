#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> asterisk;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                open.push(i);
            else if (s[i] == '*')
                asterisk.push(i);
            else {
                if (!open.empty())
                    open.pop();
                else if (!asterisk.empty())
                    asterisk.pop();
                else
                    return false;
            }
        }
        
        while (!open.empty() and !asterisk.empty()) {
            if (open.top() > asterisk.top())
                return false;
            open.pop();
            asterisk.pop();
        }
        
        return open.empty();
    }
};