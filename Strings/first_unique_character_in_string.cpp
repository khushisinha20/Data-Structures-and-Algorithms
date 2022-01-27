//leetcode.com/problems/first-unique-character-in-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int idx = -1;
        int freq[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            ++freq[s[i] - 'a'];
        }
        for (int i = 0; i < s.length(); ++i) {
            if (freq[s[i] - 'a'] == 1) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};