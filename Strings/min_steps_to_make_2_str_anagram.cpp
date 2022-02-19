//leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int min_steps = 0;
        vector<int> freq(26, 0);
        if (s == t)
            return 0;
        for (int i = 0; i < s.length(); ++i) {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] > 0) 
                min_steps += i;
        }
        return min_steps;
    }
};