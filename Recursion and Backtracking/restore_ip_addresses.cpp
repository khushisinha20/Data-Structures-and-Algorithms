//leetcode.com/problems/restore-ip-addresses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& validIpAddresses, string current, int index, string& s, int dots) {
        if (index == s.length() && dots == 4) {
            validIpAddresses.push_back(current.substr(0, current.length() - 1));
            return;
        }
        
        if (dots > 4)
            return;
        
        for (int i = index; i < min(index + 3, (int)s.length()); ++i) {
            if (stoi(s.substr(index, i - index + 1)) < 256 && (i == index || s[index] != '0')) {
                backtrack(validIpAddresses, current + s.substr(index, i - index + 1) + '.', i + 1, s, dots + 1);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> validIpAddresses;
        
        if (s.length() > 12)
            return validIpAddresses;
        
        string current;
        backtrack(validIpAddresses, current, 0, s, 0);
        
        return validIpAddresses;
    }
};