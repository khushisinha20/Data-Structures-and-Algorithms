//leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp;
        for (int i = 0; i < s.length(); ++i) {
            ++mp[s[i]];
        } 
        for (int i = 0; i < t.length(); ++i) {
            --mp[t[i]];
        }
        int min_steps = 0;
        for (auto element: mp) {
            min_steps += abs(element.second);
        }
        return min_steps / 2;
    }
};