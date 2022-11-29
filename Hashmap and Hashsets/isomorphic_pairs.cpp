//leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        unordered_map<char, int> charactersOfS;
        unordered_map<char, int> charactersOfT;
        for (int i = 0; i < s.length(); ++i) {
            if (charactersOfS.find(s[i]) == charactersOfS.end())
                charactersOfS[s[i]] = i;
            if (charactersOfT.find(t[i]) == charactersOfT.end())
                charactersOfT[t[i]] = i;
        }
        
        for (int i = 0; i < s.length(); ++i) {
            if (charactersOfS[s[i]] != charactersOfT[t[i]])
                return false;
        }
        return true;
    }
};