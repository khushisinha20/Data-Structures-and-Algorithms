//leetcode.com/problems/construct-string-with-repeat-limit/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq_of_chars(26, 0);
        for (auto& character: s)
            ++freq_of_chars[character - 'a'];
        
        string res = "";
        int occurence = 0;
        int previous_size = 0;

        while (res.length() < s.length()) {
            for (int i = 25; i >= 0; --i) {
                if (freq_of_chars[i] == 0)
                    continue;

                if (res.back() == (i + 'a') && occurence == repeatLimit)
                    continue;

                occurence = (res.back() == (i + 'a'))? occurence + 1: 1;
                res.push_back((i + 'a'));
                --freq_of_chars[i];
                break;
            }
            
            if (previous_size == res.length())
                break;

            previous_size = res.length();
        }
        return res;
    }
};