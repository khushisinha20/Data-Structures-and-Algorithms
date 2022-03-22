//leetcode.com/problems/replace-the-substring-for-balanced-string/submissions/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isSubstringBalanced(unordered_map<char, int> mp, int target) {
        for (auto i: mp)
            if (i.second > target)
                return false;
        return true;
    }
    
    int balancedString(string s) {
        int start = 0;
        int min_length = INT_MAX;
        int target = s.length() / 4;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); ++i)
            ++mp[s[i]];
        if (isSubstringBalanced(mp, target))
            return 0;
        for (int end = 0; end < s.length(); ++end) {
            --mp[s[end]];
            while (start <= end && isSubstringBalanced(mp, target)) {
                min_length = min(min_length, end - start + 1);
                ++mp[s[start]];
                ++start;
            }
        }
        return min_length;
    }
};
