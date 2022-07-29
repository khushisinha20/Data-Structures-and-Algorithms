//leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void removeLeadingZeroes(string& res) {
        while (res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
    }
    
    string smallestPossibleInteger(stack<int>& s) {
        string res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        
        removeLeadingZeroes(res);
        
        if (res.empty())
            return "0";
        
        return res;
    }
    
    string removeKdigits(string num, int k) {
        stack<int> s;
        for (int i = 0; i < num.size(); ++i) {
            while (!s.empty() && s.top() > num[i] && k) {
                s.pop();
                --k;
            }
            s.push(num[i]);
        }
        
        while (k) {
            s.pop();
            --k;
        }
        
        return smallestPossibleInteger(s);
    }
};