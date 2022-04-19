//leetcode.com/problems/repeated-dna-sequences/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> repeated_dna_sequences;
        unordered_map<string, int> mp;
        string res = s.substr(0, 10);
        ++mp[res];
        for (int i = 10; i < s.length(); ++i) {
            res = res.substr(1) + s[i];
            ++mp[res];
            if (mp[res] == 2)
                repeated_dna_sequences.push_back(res);
        }
        return repeated_dna_sequences;
    }
};