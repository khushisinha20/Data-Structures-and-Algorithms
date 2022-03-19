//practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int start = 0;
        int longest_required_substring = 0;
        unordered_map<int, int> mp;
        for (int end = 0; end < s.length(); ++end) {
            ++mp[s[end]];
            if (mp.size() == k) {
                longest_required_substring = max(longest_required_substring, end - start + 1);
            }
            while (mp.size() > k) {
                --mp[s[start]];
                if (mp[s[start]] == 0)
                    mp.erase(s[start]);
                ++start;
            }
        }
        if (mp.size() < k)
            return -1;
        return longest_required_substring;
    }
};