//leetcode.com/problems/determine-if-two-strings-are-close/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void tranform(string& word1, vector<bool>& transformationsInWord1, vector<int>& freqInWord1) {
        for (auto letter: word1) {
            ++freqInWord1[letter - 'a'];
            transformationsInWord1[letter - 'a'] = true;
        }
    }
    
    bool closeStrings(string word1, string word2) {
        vector<bool> transformationsInWord1(26, false);
        vector<bool> transformationsInWord2(26, false);
        vector<int> freqInWord1(26, 0);
        vector<int> freqInWord2(26, 0);
        
        tranform(word1, transformationsInWord1, freqInWord1);
        tranform(word2, transformationsInWord2, freqInWord2);
        
        sort(freqInWord1.begin(), freqInWord1.end());
        sort(freqInWord2.begin(), freqInWord2.end());
        
        return freqInWord1 == freqInWord2 && transformationsInWord1 == transformationsInWord2;
    }
};