//leetcode.com/problems/decoded-string-at-index/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getSize(string& s) {
        int n = s.length();
        long long size = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i]))
                size = size * (s[i] - '0');
            else
                ++size;
        }
        
        return size;
    }
    
    string decodeAtIndex(string s, int k) {
        long long size = getSize(s);
        int n = s.length();
        
        for (int i = n - 1; i >= 0; --i) {
            k %= size;
            
            if (k == 0 && isalpha(s[i])) {
                string result;
                result.push_back(s[i]);
                return result;
            }
            
            if (isalpha(s[i]))
                --size;
            else
                size = size / (s[i] - '0');
        }
        
        return "";
    }
};
