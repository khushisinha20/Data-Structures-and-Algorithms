//leetcode.com/problems/longest-repeating-character-replacement/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int maxFrequency = 0;
        unordered_map<char, int> characterFrequency;
        int longestRequiredSubstring = 0;
        
        for (int end = 0; end < s.length(); ++end) {
            ++characterFrequency[s[end]];
            maxFrequency = max(maxFrequency, characterFrequency[s[end]]);
            
            if ((end - start + 1) - maxFrequency <= k)
                longestRequiredSubstring = max(longestRequiredSubstring, end - start + 1);
            
            while ((end - start + 1) - maxFrequency > k) {
                --characterFrequency[s[start]];
                ++start;
            }
        }
        
        return longestRequiredSubstring;
    }
};