//leetcode.com/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

lass Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> anagram_positions;
        vector<int> freq_in_p(27, 0);
        vector<int> freq_in_s(27, 0);
        for (int i = 0; i < p.length(); ++i) {
            ++freq_in_p[p[i] - 'a'];
        }
        int start = 0;
        for (int end = 0; end < s.length(); ++end) {
            ++freq_in_s[s[end] - 'a'];
            if (end - start + 1 == p.length()) {
                if (freq_in_s == freq_in_p) 
                    anagram_positions.push_back(start);
                --freq_in_s[s[start] - 'a'];
                ++start;
            }
        }
        return anagram_positions;
    }
};