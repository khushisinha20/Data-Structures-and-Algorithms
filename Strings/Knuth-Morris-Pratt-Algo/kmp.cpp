#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> computeLPS(string& pattern) {
            int n = pattern.length();
            int length = 0;
            vector<int> lps(n, 0);
            lps[0] = 0;    
            
            int i = 1;
            while (i < n) {
                if (pattern[i] == pattern[length]) {
                    ++length;
                    lps[i] = length;
                    ++i;
                } else {
                    if (length != 0)
                        length = lps[length - 1];
                    else {
                        lps[i] = 0;
                        ++i;
                    }
                }
            }
            
            return lps;
        }
    
        vector <int> search(string pat, string txt) {
            vector<int> lps = computeLPS(pat);
            int n = txt.length();
            int m = pat.length();
            int i = 0;
            int j = 0;
            vector<int> result;
            
            while (i < n) {
                if (pat[j] == txt[i]) {
                    ++i;
                    ++j;
                } 
                
                if (j == m) {
                    result.push_back(i - j + 1);
                    j = lps[j - 1];
                } else if (i < n and pat[j] != txt[i]) {
                    if (j != 0)
                        j = lps[j - 1];
                    else
                        ++i;
                }
            }
            
            return result;
        }
     
};