//leetcode.com/problems/next-greater-element-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (s.length() == 1)
            return -1;
        int less_than_next = -1;
        for (int i = s.length() - 2; i >= 0; --i) {
            if (s[i] < s[i + 1]) {
                less_than_next = i;
                break;
            }
        }
        if (less_than_next == -1) 
            return -1;
        int idx = -1;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[less_than_next] < s[i]) {
                idx = i;
                break;
            }
        }
        swap(s[less_than_next], s[idx]);
        reverse(s.begin() + less_than_next + 1, s.end());
        if (stoll(s) > INT_MAX)
            return -1;
        return stoi(s);
    }
};