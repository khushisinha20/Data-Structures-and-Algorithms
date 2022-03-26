//leetcode.com/problems/smallest-string-with-a-given-numeric-value/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k -= n;
        for (int i = n - 1; i >= 0; --i) {
            ++k;
            if (k / 26 > 0) {
                s[i] = 'z';
                k -= 26;
            } else {
                s[i] = (char) (k + 96);
                break;
            }
        }
        return s;
    }
};