//leetcode.com/problems/remove-duplicate-letters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findLastOccurences(string& s, vector<int>& last_occurence) {
        for (int i = 0; i < s.length(); ++i)
            last_occurence[s[i] - 'a'] = i;
    }
    
    string removeDuplicateLetters(string s) {
        string res;
        vector<bool> visited(26, false);
        vector<int> last_occurence(26);
        findLastOccurences(s, last_occurence);
        
        for (int i = 0; i < s.length(); ++i) {
            if (visited[s[i] - 'a'])
                continue;
            
            while (!res.empty() && res.back() > s[i] && last_occurence[res.back() - 'a'] > i) {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }
            
            res.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }
        return res;
    }
};