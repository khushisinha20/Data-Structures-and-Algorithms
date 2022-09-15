//leetcode.com/problems/find-original-array-from-doubled-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_map<int, int> freq;
        vector<int> original;
        for (int i = 0; i < changed.size(); ++i) 
            ++freq[changed[i]];
        for (int i = 0; i < changed.size(); ++i) {
            if (freq[changed[i]] == 0)
                continue;
            if (changed[i] == 0) {
                if (freq[0] > 0 && freq[0] % 2 == 0) {
                    original.push_back(0);
                    freq[0] -= 2;
                }
                continue;
            }
            if (freq[changed[i] * 2] > 0) {
                original.push_back(changed[i]);
                --freq[changed[i] * 2];
                --freq[changed[i]];
            }
        }
        if (original.size() * 2 == changed.size())
            return original;
        return {};
    }
};