//leetcode.com/problems/longest-repeating-character-replacement/submissions/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int max_frequency = 0;
        int longest_required_substring = 0;
        unordered_map<char, int> mp;
        for (int end = 0; end < s.length(); ++end) {
            ++mp[s[end]];
            max_frequency = max(max_frequency, mp[s[end]]);
            if ((end - start + 1) - max_frequency <= k) {
                longest_required_substring = max(longest_required_substring, end - start + 1);
            }
            while (((end - start + 1) - max_frequency > k)) {
                --mp[s[start]];
                ++start;
            }   
        }
        return longest_required_substring;
    }
};