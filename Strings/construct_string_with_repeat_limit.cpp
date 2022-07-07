//leetcode.com/problems/construct-string-with-repeat-limit/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res = "";
        int repeatOccurence = 0;
        vector<int> freq(26, 0);
        int prevsize = -1;
        for (auto& i: s)
            ++freq[i - 'a'];
    
        while (res.size() < s.size()) {
            for (int i = 25; i >= 0; --i) {
                if (freq[i] == 0)
                    continue;

                if (res.back() == (i + 'a') && repeatOccurence == repeatLimit)
                    continue;

                if (res.back() == (i + 'a'))
                    ++repeatOccurence;
                else
                    repeatOccurence = 1;

                res.push_back(i + 'a');
                --freq[i];
                break;
            }
            if (prevsize == res.size()) //to check if no more characters are being added
                break;
            
            prevsize = res.size();
        }
        
        return res;
    }
};