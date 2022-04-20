//leetcode.com/problems/group-anagrams/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(s);
        }
        vector<vector<string>> result;
        for (auto i: mp) {
            result.push_back(i.second);
        }
        return result;
    }
};