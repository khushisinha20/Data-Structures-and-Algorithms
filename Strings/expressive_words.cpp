//leetcode.com/problems/expressive-words/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isExpressive(string& s, string& word) {
        int first = 0;
        int second = 0;
        
        while (first < s.length() && second < word.length()) {
            int currentInS = first;
            int currentInWord = second;
            int frequencyInS = 0;
            int frequencyInWord = 0;
            
            while (first < s.length()) {
                if (s[currentInS] != s[first])
                    break;
                ++first;
                ++frequencyInS;
            }
            
            while (second < word.length()) {
                if (word[currentInWord] != word[second])
                    break;
                ++second;
                ++frequencyInWord;
            }
            
            if (s[currentInS] != word[currentInWord] || frequencyInWord > frequencyInS || frequencyInS - frequencyInWord == 1 && frequencyInS <= 2)
                return false;
            
        }
        return first == s.length() and second == word.length();
    }
    
    int expressiveWords(string s, vector<string>& words) {
        int expressiveWordsCount = 0;
        
        for (auto& word: words)
            if (isExpressive(s, word))
                ++expressiveWordsCount;
        
        return expressiveWordsCount;
    }
};