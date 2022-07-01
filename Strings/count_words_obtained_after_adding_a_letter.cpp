//leetcode.com/problems/count-words-obtained-after-adding-a-letter/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortStartWords(vector<string>& startWords) {
        for (auto &word: startWords)
            sort(word.begin(), word.end());
    }
    
    void sortTargetWords(vector<string>& targetWords) {
        for (auto &word: targetWords)
            sort(word.begin(), word.end());
    }
    
    void fillHashSet(set<string>& hash, vector<string>& words) {
        for (auto word: words)
            hash.insert(word);
    }
    
    bool canBeConverted(string& word, set<string>& start) {
        string s = "";
        for (int i = 0; i < word.length(); ++i) {
            for (int j = 0; j < word.length(); ++j) {
                if (j != i)
                    s.push_back(word[j]);
            }
            if (start.find(s) != start.end()) 
                return true;
            s.clear();
        }
        return false;
    }
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        sortStartWords(startWords);
        sortTargetWords(targetWords);
        set<string> start;
        fillHashSet(start, startWords);
        int word_count = 0;
        for (auto word: targetWords) {
            if (canBeConverted(word, start))
                ++word_count;
        }
        return word_count;
    }
};