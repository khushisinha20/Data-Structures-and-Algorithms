//leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int longest_required_substring = 0;
        unordered_set<char> unique_chars;
        for (int end = 0; end < s.length(); ++end) {
            unique_chars.insert(s[end]);
            if (unique_chars.size() == (end - start + 1)) {
                longest_required_substring = max(longest_required_substring, end - start + 1);
            }
            while ((end - start + 1) > unique_chars.size()) {
                unique_chars.erase(s[start]);
                unique_chars.insert(s[end]);
                ++start;
            }
        }
        return longest_required_substring;
    }
};