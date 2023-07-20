//leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include <bits/stdc++.h>
using  namespace std;

class Solution {
public:
    unordered_map<char, int> getFrequency(string& s) {
        unordered_map<char, int> frequency;
        for (int i = 0; i < s.length(); ++i)
            ++frequency[s[i]];
        return frequency;
    }

    vector<int> getOccurrence(unordered_map<char, int>& frequency) {
        vector<int> occurrence;
        for (auto& entry : frequency)
            occurrence.push_back(entry.second);
        return occurrence;
    }

    int minDeletions(string s) {
        auto frequency = getFrequency(s);
        auto occurrence = getOccurrence(frequency);
        sort(occurrence.rbegin(), occurrence.rend());
        int deletions = 0;

        for (int i = 1; i < occurrence.size(); ++i) {
            if (occurrence[i] >= occurrence[i - 1]) {
                int target = max(occurrence[i - 1] - 1, 0);
                deletions += (occurrence[i] - target);
                occurrence[i] = target;
            }
        }

        return deletions;
    }
};