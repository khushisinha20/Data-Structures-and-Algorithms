//leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, int> getFrequency(string& s) {
        unordered_map<char, int> frequency;
        for (auto& entry: s)
            ++frequency[entry];
        return frequency;
    }
    
    vector<int> getOccurences(unordered_map<char, int>& frequency) {
        vector<int> occurence;
        for (auto& entry: frequency)
            occurence.push_back(entry.second);
        return occurence;
    }
    
    int minDeletions(string s) {
        unordered_map<char, int> frequency = getFrequency(s);
        vector<int> occurence = getOccurences(frequency);
        
        sort(occurence.rbegin(), occurence.rend());
        int deletions = 0;
        
        for (int i = 1; i < occurence.size(); ++i) {
            if (occurence[i] >= occurence[i - 1]) {
                int target = max(occurence[i - 1] - 1, 0);
                deletions += (occurence[i] - target);
                occurence[i] = target;
            }
        }
        
        return deletions;
    }
};