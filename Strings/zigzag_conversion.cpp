//leetcode.com/problems/zigzag-conversion/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows_of_s(numRows, "");
        int start = 0;
        while (start < s.length()) {
            for (int i = 0; i < numRows && start < s.length(); ++i) {
                rows_of_s[i].push_back(s[start++]);
            }
            for (int i = numRows - 2; i >= 1 && start < s.length(); --i) {
                rows_of_s[i].push_back(s[start++]);
            }
        }
        string res = "";
        for (int i = 0; i < rows_of_s.size(); ++i) {
            res += rows_of_s[i];
        }
        return res;
    }
};
