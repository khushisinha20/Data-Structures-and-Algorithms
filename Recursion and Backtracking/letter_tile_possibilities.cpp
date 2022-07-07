//leetcode.com/problems/letter-tile-possibilities/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateAndCountPossibilities(vector<int>& freq, int& res) {
        for (int i = 0; i < 26; ++i) {
            if (freq[i]) {
                --freq[i];
                ++res;
                generateAndCountPossibilities(freq, res);
                ++freq[i];
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (auto tile: tiles)
            ++freq[tile - 'A'];
        
        int res = 0;
        generateAndCountPossibilities(freq, res);
        return res;
    }
};