//leetcode.com/problems/decode-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeStringUtil(int& index, string& s) {
        string result;
        
        while (index < s.length() and s[index] != ']') {
            if (!isdigit(s[index])) {
                result += s[index++];
            } else {
                int num = 0;
                while (index < s.length() and isdigit(s[index]))
                    num = num * 10 + (s[index++] - '0');
                ++index;
                string intermediate = decodeStringUtil(index, s);
                ++index;
                
                while (num--)
                    result += intermediate;
            }
        }
        
        return result;
    }
    
    string decodeString(string s) {
        int index = 0;
        return decodeStringUtil(index, s);
    }
};