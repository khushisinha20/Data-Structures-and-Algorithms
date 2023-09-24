//leetcode.com/problems/word-break-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string join(vector<string>& words) {
        string sentence;
        
        for (int i = 0; i < words.size(); ++i) {
            sentence += words[i];
            if (i < words.size() - 1)
                sentence += " ";
        }
        
        return sentence;
    }
    
    void backtrack(string& s, unordered_set<string>& wordSet, int index, vector<string>& result, vector<string>& current) {
        if (index == s.length()) {
            result.push_back(join(current));
            return;
        }
        
        for (int end = index + 1; end <= s.length(); ++end) {
            string word = s.substr(index, end - index); 
            if (wordSet.count(word)) {
                current.push_back(word);
                backtrack(s, wordSet, end, result, current);
                current.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> result;
        vector<string> current;
        backtrack(s, wordSet, 0, result, current);
        return result;
    }
};