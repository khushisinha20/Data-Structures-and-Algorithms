//leetcode.com/problems/implement-strstr

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lpsArray(string& s) {
        vector<int> lps(s.length(), 0);
        int i = 1;
        int len = 0;
        while (i < s.length()) {
            if (s[i] == s[len]) {
                ++len;
                lps[i] = len;
                ++i;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    ++i;
                }
            }
        }
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        vector<int> lps = lpsArray(needle);
        for (int i = 0, j = 0; i < haystack.size();) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == needle.size()) {
                return i - j;
            }
            if (i < haystack.size() && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
        
    }
};